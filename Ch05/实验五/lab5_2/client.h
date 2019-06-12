#ifndef _CLIENT_H
#define _CLIENT_H

class CLIENT {
public: 
    static char ServerName;
    static int ClientNum;
    CLIENT();
    ~CLIENT();
    static void ChangeServerName(const char& x);
};

#endif