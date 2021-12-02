#include <bits/stdc++.h>
using namespace std;

const int N = 10000 + 5;
struct IP {
    int state;   //1未分配 2待分配 3占用 4过期
    int time;
    string host;
}ip[N];

int main() {
    int n,tdef,tmax,tmin;
    string host;
    cin >> n >> tdef >> tmax >> tmin >> host;
    for(int i = 1; i <= n; i++) {
        ip[i].state = 1;
    }
    int count;
    cin >> count;
    while(count--) {
        int seq, rip, time;
        string shost,rhost,type;
        cin >> seq >> shost >> rhost >> type >> rip >> time;

        for(int i = 1; i <= n; i++) {
            if(ip[i].time <= seq) {
                if(ip[i].state == 2) {
                    ip[i].state = 1;
                    ip[i].host = "";
                    ip[i].time = 0;
                }
                else if(ip[i].state == 3) {
                    ip[i].state = 4;
                    ip[i].time = 0;
                }
            }
        }
        if(rhost == host || rhost == "*" || type == "REQ") {
            if(type != "DIS" && type != "REQ") continue;
            if((rhost == "*" && type != "DIS") || (rhost == host && type == "DIS")) continue;
            if(type == "DIS") {
                int select = -1;
                for(int i = 1; i <= n; i ++) {
                    if(ip[i].state != 1 && ip[i].host == shost) {
                        select = i;
                        break;
                    }
                }
                if(select == -1) {
                    for(int i = 1; i <= n; i++) {
                        if(ip[i].state == 1) {
                            select = i;
                            break;
                        }
                    }
                }
                if(select == -1) {
                    for(int i = 1; i <= n; i++) {
                        if(ip[i].state == 4) {
                            select = i;
                            break;
                        }
                    }
                }
                if(select != -1) {
                    ip[select].state = 2;
                    ip[select].host = shost;
                    if(time == 0) 
                        ip[select].time = seq + tdef;
                    else if(time - seq >= tmin && time - seq <= tmax) 
                        ip[select].time = time;
                    else if(time - seq < tmin)
                        ip[select].time = seq + tmin;
                    else if(time - seq > tmax)
                        ip[select].time = seq + tmax;
                    cout << host << " " << shost << " OFR " << select << " " << ip[select].time << endl;
                }
            }
            else if(type == "REQ") {
                if(rhost != host) {
                    for(int i = 1; i <= n; i++) {
                        if(ip[i].host == shost) {
                            if(ip[i].state == 2) {
                                ip[i].state = 1;
                                ip[i].host = "";
                                ip[i].time = 0;
                            }
                        }
                    } 
                }
                else {
                    if(rip >= 1&& rip <= n && ip[rip].host == shost) {
                        ip[rip].state = 3;
                        if(time == 0) 
                            ip[rip].time = seq + tdef;
                        else if(time - seq >= tmin && time - seq <= tmax) 
                            ip[rip].time = time;
                        else if(time - seq < tmin)
                            ip[rip].time = tmin + seq;
                        else if(time - seq > tmax)
                            ip[rip].time = tmax + seq;
                        cout << host << " " << shost << " ACK " << rip << " " << ip[rip].time << endl;
                    }
                    else {
                        cout << host << " " << shost << " NAK " << rip << " 0" << endl;
                    }
                } 
            }
        }
    }
    return 0;
}