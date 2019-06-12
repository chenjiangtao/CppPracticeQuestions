#include "client.h"

char CLIENT::ServerName = 'a';
int CLIENT::ClientNum = 0;

CLIENT::CLIENT() {
    ClientNum++;
}

CLIENT::~CLIENT() {
    ClientNum--;
}

void CLIENT::ChangeServerName(const char& x) {
    ServerName = x;
}