#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class WhiteRabbitNeo {
private:
    string target;
    vector<string> ports;
    vector<string> vulnerabilities;

public:
    WhiteRabbitNeo(string t) {
        target = t;
        ports = {"80", "443", "8080", "8443"};
        vulnerabilities = {"XSS", "SQLi", "CSRF", "RFI", "LFI", "RCE"};
    }

    void scanPorts() {
        cout << "Scanning ports..." << endl;
        for (string port : ports) {
            string cmd = "nmap -p " + port + " " + target;
            system(cmd.c_str());
        }
    }

    void scanVulnerabilities() {
        cout << "Scanning for vulnerabilities..." << endl;
        for (string vuln : vulnerabilities) {
            string cmd = "nmap --script vuln -p " + getRandomPort() + " " + target;
            system(cmd.c_str());
        }
    }

    string getRandomPort() {
        srand(time(0));
        int randomIndex = rand() % ports.size();
        return ports[randomIndex];
    }
};

int main() {
    string target;
    cout << "Enter target IP or domain: ";
    cin >> target;

    WhiteRabbitNeo scanner(target);
    scanner.scanPorts();
    scanner.scanVulnerabilities();

    return 0;
}