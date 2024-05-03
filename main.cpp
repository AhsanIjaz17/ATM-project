#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <conio.h>
#include "Account.h"
using namespace std;

int main() {
    system("COLOR 02"); //Set console color to green
    // creating Account obj
    Account obj;
    bool loginValid = false;

    loginValid = obj.login();

    if (!loginValid) {
        return 0; // Terminate the program if login is disabled
    }
    obj.menu();
}
