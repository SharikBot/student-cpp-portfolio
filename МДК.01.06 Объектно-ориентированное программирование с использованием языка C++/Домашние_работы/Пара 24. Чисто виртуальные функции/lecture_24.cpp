
#include <iostream>
#include <string>
using namespace std;

// ===== Abstract base class =====
class Notification {
public:
    virtual void send() = 0; // pure virtual function
    virtual ~Notification() {}
};


// ===== Email notification =====
class EmailNotification : public Notification {
private:
    string email;

public:
    EmailNotification(const string& addr) {
        email = addr;
    }

    void send() override {
        cout << "Email sent to: " << email << endl;
    }
};


// ===== SMS notification =====
class SMSNotification : public Notification {
private:
    string phone;

public:
    SMSNotification(const string& number) {
        phone = number;
    }

    void send() override {
        cout << "SMS sent to: " << phone << endl;
    }
};


// ===== Push notification =====
class PushNotification : public Notification {
private:
    string device;

public:
    PushNotification(const string& deviceName) {
        device = deviceName;
    }

    void send() override {
        cout << "Push notification sent to: " << device << endl;
    }
};


// ===== main =====
int main() {
    Notification* n1 = new EmailNotification("user@mail.com");
    Notification* n2 = new SMSNotification("+123456789");
    Notification* n3 = new PushNotification("Android Device");

    n1->send();
    n2->send();
    n3->send();

    delete n1;
    delete n2;
    delete n3;

    return 0;
}