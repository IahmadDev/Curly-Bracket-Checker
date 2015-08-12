#ifndef FILEINFO
#define FILEINFO
#include <QString>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>

#define debugLog "Logs/debuglog.txt"

// variables

QString FileName;
QString Data;
int FileSize = 0;
int OpenBrackets = 0;
int ClosedBrackets = 0;
int CurrentNumber = 0;
int MaxLines = 0;

// Functions declaration

// File functions
void ReadFile(QString filename); // reading opened file

// Set funcions
void SetMaxLines(int line);
void SetFileName(QString filename); // seting filename - used in QMessage::information
void SetFileSize(int filesize); // seting filesize - used in QMessage::information

// Get Functions
int GetMaxLines();
QString GetFileName();
int GetFileSize();
QString GetData();

// Brackets function
int GetOpenedBracket();
int GetClosedBracket();

// Debug functions

void ResetData();
void LogWrite(QString filename, QString str);

// Fuctions definitions

// Set Functions
void SetMaxLines(int line){ MaxLines = line; }
void SetFileName(QString filename){ FileName.replace(0, filename.length(), filename); }
void SetFileSize(int filesize){ FileSize = filesize; }

// Get Functions
QString GetFileName(){ return FileName; }
int GetFileSize(){ return FileSize; }
int GetMaxLines(){ return MaxLines; }
QString GetData(){ return Data; }
int GetCurrentNumber(){ return MaxLines; }


void ReadFile(QString filename){
    ResetData();
    QFile fajl(filename);
    QTextStream ts(&fajl);
    if(!fajl.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::warning(0,
                                 "Curly Bracket Checker",
                                 "Error while loading file");
        return;
    }
    SetFileName(fajl.fileName());
    QString tempstro, tempstrc;
    while(!fajl.atEnd()){
        QString currentLine = ts.readLine(0);
        CurrentNumber++;
        for(int i = 0;i < currentLine.size();i++){
            if(currentLine.at(i) == QChar('}')){
                ClosedBrackets++;
                tempstrc = "} found on line number " + QString::number(CurrentNumber) +".\n";
                Data += tempstrc;
            }
            if(currentLine.at(i) == QChar('{')){
                OpenBrackets++;
                tempstro = "{ found on line number " + QString::number(CurrentNumber) +".\n";
                Data += tempstro;
            }
        }
    }
    fajl.close();
}

int GetOpenedBracket(){
    return OpenBrackets;
}

int GetClosedBracket(){
    return ClosedBrackets;
}

void ResetData(){
    OpenBrackets = 0;
    ClosedBrackets = 0;
    Data.clear();
}


#endif // FILEINFO

