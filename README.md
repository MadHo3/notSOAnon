notSOAnon

![banner](banner.png)

A C++ tool that analyzes Telegram chat export JSON files and reveals the real numeric user ID behind anonymous chat bots.

🚀 What does it do?

Telegram “anonymous chat” bots hide the real user identity.
However, Telegram exports the entire raw chat data — including encoded identifiers.

This tool:

1. Parses Telegram exported .json files


2. Finds Base64-encoded user identifiers


3. Decodes them


4. Prints the real numeric Telegram user ID



⚠️ It does NOT hack Telegram.
It simply reads the data YOU exported from your own device.


---

📥 How to get JSON from Telegram

🟢 Method: from inside the anonymous chat

1. Open the anonymous chat / bot conversation


2. Tap the three dots (⋮) in the top-right corner


3. Select Export chat


4. Choose JSON format


5. Confirm export