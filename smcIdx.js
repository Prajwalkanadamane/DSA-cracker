const {onCall, HttpsError} = require("firebase-functions/v2/https");
const {onDocumentUpdated} = require("firebase-functions/v2/firestore");
const {onSchedule} = require("firebase-functions/v2/scheduler");
const {defineSecret} = require("firebase-functions/params");
const admin = require("firebase-admin");
const nodemailer = require("nodemailer");

admin.initializeApp();

// The delay helper function to prevent spam detection
const delay = (ms) => new Promise(resolve => setTimeout(resolve, ms));

const outlookEmail = defineSecret("OUTLOOK_EMAIL");
const outlookPassword = defineSecret("OUTLOOK_PASSWORD");

const getTransporter = (email, password) => {
  return nodemailer.createTransport({
    host: "smtp.gmail.com",
    port: 465,
    secure: true, 
    auth: { 
      user: email, 
      pass: password 
    }
  });
};

// ============================================================
// 1. ONBOARDING TEMPLATE (Used for Auth Credentials)
// ============================================================
const getOnboardingHtml = (name, email, credentialText) => `
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Your Login Credentials</title>
  <style>
    body, table, td, p, a, h1, h2 {
      -webkit-text-size-adjust: 100%;
      -ms-text-size-adjust: 100%;
    }
  </style>
</head>
<body style="margin: 0; padding: 20px 10px; background-color: #f0f4f8; font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Helvetica, Arial, sans-serif;">
  <table align="center" border="0" cellpadding="0" cellspacing="0" width="100%" style="max-width: 450px; background-color: #ffffff; border-radius: 8px; margin: 0 auto; box-shadow: 0 4px 15px rgba(0,0,0,0.05); overflow: hidden;">
    <tr>
      <td align="center" style="background-color: #0D47A1; padding: 20px 15px;">
        <h1 style="color: #ffffff; margin: 0; font-size: 15px; font-weight: 600; text-transform: uppercase; letter-spacing: 0.5px; line-height: 1.4;">
          Ballari Institute of Technology & Management
        </h1>
        <p style="color: #90caf9; margin: 4px 0 0 0; font-size: 12px; font-weight: 700; letter-spacing: 1px;">
          (BITM)
        </p>
      </td>
    </tr>
    <tr>
      <td style="padding: 25px 20px;">
        <h2 style="margin-top: 0; margin-bottom: 12px; color: #1e293b; font-size: 18px; font-weight: 600;">Your Login Credentials</h2>
        <p style="color: #475569; font-size: 14px; line-height: 1.5; margin-bottom: 20px;">
          Hello ${name},<br><br>Welcome to the SmartCampus Hostel Management System. Your account has been created successfully. Here are your Login credentials:
        </p>
        <table border="0" cellpadding="0" cellspacing="0" width="100%" style="background-color: #f8fafc; border-radius: 6px; border: 1px solid #e2e8f0;">
          <tr>
            <td style="padding: 15px;">
              <p style="color: #64748b; font-size: 11px; font-weight: 700; margin: 0 0 4px 0; text-transform: uppercase; letter-spacing: 0.5px;">Website Portal</p>
              <p style="margin: 0 0 15px 0; word-break: break-all;">
                <a href="https://smartpassver1.web.app" style="color: #0D47A1; font-size: 14px; font-weight: 500; text-decoration: none;">https://smartpassver1.web.app</a>
              </p>
              <p style="color: #64748b; font-size: 11px; font-weight: 700; margin: 0 0 4px 0; text-transform: uppercase; letter-spacing: 0.5px;">Registered Email</p>
              <p style="color: #1e293b; font-size: 14px; margin: 0 0 15px 0; font-weight: 500; word-break: break-all;">${email}</p>
              <p style="color: #64748b; font-size: 11px; font-weight: 700; margin: 0 0 4px 0; text-transform: uppercase; letter-spacing: 0.5px;">Password</p>
              <p style="color: #1e293b; font-size: 15px; margin: 0; font-family: monospace; font-weight: bold; letter-spacing: 1px; background-color: #e2e8f0; padding: 6px 10px; border-radius: 4px; display: inline-block;">${credentialText}</p>
            </td>
          </tr>
        </table>
        <table border="0" cellpadding="0" cellspacing="0" width="100%" style="margin-top: 25px;">
          <tr>
            <td align="center">
              <a href="https://smartpassver1.web.app" style="background-color: #0D47A1; color: #ffffff; padding: 12px 28px; text-decoration: none; border-radius: 5px; font-weight: 600; font-size: 15px; display: inline-block;">Log In Now</a>
            </td>
          </tr>
        </table>
      </td>
    </tr>
    <tr>
      <td align="center" style="background-color: #f8fafc; padding: 15px 20px; border-top: 1px solid #e2e8f0;">
         <p style="font-size: 11px; color: #94a3b8; margin: 0; line-height: 1.5;">
           &copy; ${new Date().getFullYear()} SmartCampus Hostel Management.<br>Please do not reply to this automated email.
         </p>
      </td>
    </tr>
  </table>
</body>
</html>
`;


// ============================================================
// 2. CLOUD FUNCTIONS
// ============================================================

// 1. CREATE USER (Emails initial password)
exports.createUser = onCall({ secrets: [outlookEmail, outlookPassword] }, async (request) => {
  if (!request.auth) throw new HttpsError("unauthenticated", "Login required.");
  const callerDoc = await admin.firestore().collection("users").doc(request.auth.uid).get();
  if (callerDoc.data().role !== "Admin" && callerDoc.data().role !== "Warden") throw new HttpsError("permission-denied", "Unauthorized.");

  const { email, password, name, role, block, usn, room_number, student_phone, parent_phone, phone, skip_email } = request.data;

  let finalPassword = password;
  let isGeneratedPassword = false;
  
  if (!finalPassword) {
    const chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%&*";
    finalPassword = Array.from({length: 10}, () => chars[Math.floor(Math.random() * chars.length)]).join('');
    isGeneratedPassword = true;
  }

  let userRecord;
  try {
    userRecord = await admin.auth().createUser({ email, password: finalPassword, displayName: name });
  } catch (error) { throw new HttpsError("internal", error.message); }

  await admin.firestore().collection("users").doc(userRecord.uid).set({
    uid: userRecord.uid, name, email, role, block: block || null,
    usn: usn || "N/A", room_number: room_number || "N/A",
    student_phone: student_phone || "N/A", parent_phone: parent_phone || "N/A",
    phone: phone || null, 
    email_sent: false,
    created_at: admin.firestore.FieldValue.serverTimestamp(),
  });

  const shouldSendEmail = (!skip_email || isGeneratedPassword) && ['Student', 'Warden', 'Security'].includes(role);

  if (shouldSendEmail) {
    try {
      const transporter = getTransporter(outlookEmail.value(), outlookPassword.value());
      await transporter.sendMail({
        from: `"SmartCampus" <${outlookEmail.value()}>`,
        to: email,
        subject: "🔐 Your Login Credentials",
        html: getOnboardingHtml(name, email, finalPassword) 
      });
      await admin.firestore().collection("users").doc(userRecord.uid).update({ email_sent: true });
    } catch (err) { 
      console.error("Auto-email failed:", err); 
      throw new HttpsError("internal", `User saved, but Gmail rejected the email: ${err.message}`);
    }
  }

  return { success: true, message: `User ${email} created!` };
});

// 2. QUEUE PARENT SMS (Fast Trigger)
exports.queuePassNotification = onDocumentUpdated({ document: "passes/{passId}" }, async (event) => {
  const newValue = event.data.after.data();
  const oldValue = event.data.before.data();
  
  const isExit = newValue.status === "Out" && oldValue.status !== "Out";
  const isReturn = newValue.return_time && !oldValue.return_time;

  if (!isExit && !isReturn) return;

  const userSnap = await admin.firestore().collection("users").doc(newValue.student_uid).get();
  if (!userSnap.exists) return;
  
  const parentMobile = userSnap.data().parent_phone;
  if (!parentMobile || parentMobile.length < 10) return;

  const now = new Date();
  const timeStr = now.toLocaleTimeString('en-IN', { timeZone: 'Asia/Kolkata', hour: '2-digit', minute: '2-digit', hour12: true }); 

  await admin.firestore().collection("sms_queue").add({
    parentMobile: parentMobile,
    student_name: newValue.student_name,
    reason: newValue.reason || "General Outing", 
    isExit: isExit,
    scan_time: timeStr.toUpperCase(),
    status: "pending",
    created_at: admin.firestore.FieldValue.serverTimestamp()
  });
  
  console.log(`Added SMS to queue for ${newValue.student_name}`);
});

// 3. PROCESS SMS QUEUE (Rate-Limiter Cron Job)
exports.processSmsQueue = onSchedule("every 1 minutes", async (event) => {
  const db = admin.firestore();
  
  const snapshot = await db.collection("sms_queue")
    .where("status", "==", "pending")
    .orderBy("created_at", "asc")
    .limit(25)
    .get();

  if (snapshot.empty) return;

  const SMS_USERNAME = "newbitm";
  const SMS_API_KEY = "a47qcSOKOhPcsg48lWiw";
  const SENDER_ID = "BITMBR";
  const BASE_URL = "https://smshorizon.co.in/api/sendsms.php";

  for (const doc of snapshot.docs) {
    const data = doc.data();

    const safeName = String(data.student_name).trim().substring(0, 30);
    const safeTime = String(data.scan_time).trim().substring(0, 30);
    const safeReason = String(data.reason || "General Outing").trim().substring(0, 30); 

    let message = "";
    let tid = "";

    if (data.isExit) {
      tid = "1207177468495469466";
      message = `Dear Parent, your ward ${safeName} exited hostel at ${safeTime} for ${safeReason}. If unaware, contact hostel warden. - BITM Ballari Powered by Contineo`;
    } else {
      tid = "1207177468238511210";
      message = `Dear Parent, your ward ${safeName} returned to hostel at ${safeTime} after ${safeReason}. If unaware, contact hostel warden. - BITM Ballari Powered by Contineo`;
    }

    const requestUrl = `${BASE_URL}?user=${SMS_USERNAME}&apikey=${SMS_API_KEY}&mobile=${data.parentMobile}&message=${encodeURIComponent(message)}&senderid=${SENDER_ID}&type=txt&tid=${tid}`;

    try {
      const response = await fetch(requestUrl);
      const result = await response.text();
      
      await doc.ref.update({ 
        status: "sent", 
        message_id: result, 
        sent_at: admin.firestore.FieldValue.serverTimestamp() 
      });
      console.log(`[SENT] SMS to ${data.parentMobile} - ID: ${result}`);
      
    } catch (err) {
      await doc.ref.update({ 
        status: "failed", 
        error: err.message, 
        failed_at: admin.firestore.FieldValue.serverTimestamp() 
      });
      console.error("[FAILED] SMS Error:", err);
    }

    await delay(2000); 
  }
});

// 4. BULK ONBOARDING (Emails)
exports.sendBulkOnboarding = onCall(
  { secrets: [outlookEmail, outlookPassword], timeoutSeconds: 540, memory: "256MiB" }, 
  async (request) => {
    if (!request.auth) throw new HttpsError("unauthenticated", "Login required.");
    const transporter = getTransporter(outlookEmail.value(), outlookPassword.value());
    const usersRef = admin.firestore().collection("users");

    const snapshot = await usersRef
      .where("role", "in", ["Student", "Warden", "Security"])
      .where("email_sent", "==", false)
      .limit(50) 
      .get();

    if (snapshot.empty) return { message: "No users found who need emails." };

    let successCount = 0;

    for (const doc of snapshot.docs) {
      const s = doc.data();
      if (!s.email || !s.email.includes("@")) continue;

      let fallbackText = "Please click 'Forgot Password' on the login screen to set up your account.";

      try {
        await transporter.sendMail({
          from: `"SmartCampus" <${outlookEmail.value()}>`,
          to: s.email,
          subject: "🔐 Access Your Account",
          html: getOnboardingHtml(s.name, s.email, fallbackText)
        });
        
        await doc.ref.update({ email_sent: true });
        successCount++;
        
        await delay(2000); 

      } catch (e) { 
        console.error(`Failed to send to ${s.email}:`, e); 
      }
    }

    return { success: true, message: `Batch Complete: Sent ${successCount} emails.` };
});

// ============================================================================
// 5. DELETE USER (Atomizes Auth, Profile Record, and ALL Linked Passes)
// ============================================================================
exports.deleteUser = onCall(async (request) => {
  if (!request.auth) throw new HttpsError("unauthenticated", "Login required.");
  const callerDoc = await admin.firestore().collection("users").doc(request.auth.uid).get();
  if (callerDoc.data().role !== "Admin") throw new HttpsError("permission-denied", "Admins only.");
  
  const { targetUid } = request.data;
  try {
    await admin.auth().deleteUser(targetUid);
    await admin.firestore().collection("users").doc(targetUid).delete();
    
    // ✅ SURGICAL CASCADING BACKSTOP: Atomizes every pass tied to this student
    const passesSnap = await admin.firestore().collection("passes").where("student_uid", "==", targetUid).get();
    await Promise.all(passesSnap.docs.map(d => d.ref.delete()));

    return { success: true, message: "User account and linked pass history deleted." };
  } catch (error) { throw new HttpsError("internal", error.message); }
});

// 6. AUTO-CLEANUP: Delete Expired Pending Passes 
exports.cleanupExpiredPasses = onSchedule("every 1 hours", async (event) => {
  const now = new Date();
  const db = admin.firestore();
  try {
    const snapshot = await db.collection("passes")
      .where("status", "==", "Pending")
      .where("to_date", "<", now) 
      .get();

    if (snapshot.empty) {
      console.log("No expired pending passes found.");
      return;
    }

    const batch = db.batch();
    snapshot.docs.forEach((doc) => {
      batch.delete(doc.ref);
    });

    await batch.commit();
    console.log(`Cleanup Successful: Deleted ${snapshot.size} expired pending passes.`);
    
  } catch (error) {
    console.error("Error cleaning up expired passes:", error);
  }
});

// ============================================================================
// 7. AUTO-CLEANUP: Purge Orphaned Active Passes (Clears stuck graduated students)
// ============================================================================
exports.purgeOrphanedPasses = onSchedule("every 1 hours", async (event) => {
  const db = admin.firestore();
  try {
    const activePasses = await db.collection("passes")
      .where("status", "in", ["Pending", "Approved", "Out", "SpecialCase"])
      .get();

    if (activePasses.empty) return;

    let purgedCount = 0;
    const deletePromises = [];

    for (const passDoc of activePasses.docs) {
      const uid = passDoc.data().student_uid;
      if (!uid) continue;

      const userDoc = await db.collection("users").doc(uid).get();
      if (!userDoc.exists) {
        deletePromises.push(passDoc.ref.delete());
        purgedCount++;
      }
    }

    await Promise.all(deletePromises);
    if (purgedCount > 0) {
      console.log(`[ORPHAN SWEEP]: Atomized ${purgedCount} ghost passes belonging to deleted accounts.`);
    }
  } catch (error) {
    console.error("Orphan sweep failure:", error);
  }
});