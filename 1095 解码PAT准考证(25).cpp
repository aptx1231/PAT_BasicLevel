#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct node {
	int score;
	char id[15];
	bool operator< (const node & t) const {
		if (score > t.score) {
			return 1;
		}
		else if (score < t.score) {
			return 0;
		}
		else if (strcmp(id, t.id) < 0) {
			return 1;
		}
		else if (strcmp(id, t.id) > 0) {
			return 0;
		}
	}
}a[10005],b[10005],t[10005];

struct idnum{
	int id; //¿¼³¡
	int cnt; //ÈËÊı 
	bool operator< (const idnum & t) const {
		if (cnt > t.cnt) {
			return 1;
		}
		else if (cnt < t.cnt) {
			return 0;
		}
		else {
			return id < t.id;
		}
	}
}c[1000];

struct point{
	int roomId;
	int time; 
}d[10005];

int roomCnt[1000];
int roomScore[1000];

void out(node q[], int l) {
	if (l == 0) {
		printf("NA\n");
		return;
	}
	for (int i=0;i<l;i++) {
		printf("%s %d\n",q[i].id, q[i].score);
	}
}

int main() {
	int n,m;
	scanf("%d %d",&n,&m);
    char s[20];
    int score;
    int la=0,lb=0,lt=0;
	for (int i=0;i<n;i++) {
		scanf("%s %d",s,&score);
		int roomid = (s[1]-'0')*100 + (s[2]-'0')*10 + (s[3]-'0')*1;
		roomScore[roomid] += score;
		roomCnt[roomid]++;
		if (s[0] == 'A') {
			strcpy(a[la].id, s);
			a[la].score = score;
			la++;
		}
		else if (s[0] == 'B') {
			strcpy(b[lb].id, s);
			b[lb].score = score;
			lb++;
		}
		else if (s[0] == 'T') {
			strcpy(t[lt].id, s);
			t[lt].score = score;
			lt++;
		}
		d[i].roomId = (s[1]-'0')*100 + (s[2]-'0')*10 + (s[3]-'0');
		d[i].time = (s[4]-'0')*100000 + (s[5]-'0')*10000 + (s[6]-'0')*1000 + (s[7]-'0')*100 
						+ (s[8]-'0')*10 + (s[9]-'0'); 
	}
 	sort(a,a+la);
	sort(b,b+lb);
	sort(t,t+lt);
	int kind;
	for (int i=1;i<=m;i++) {
		scanf("%d",&kind);
		if (kind == 1) {
			char l[2];
			scanf("%s",l);
			printf("Case %d: 1 %c\n",i,l[0]);
			if (l[0] == 'A') {
				out(a,la);
			}
			else if (l[0] == 'B') {
				out(b,lb);
			}
			else if (l[0] == 'T') {
				out(t,lt);
			} 
		}
		else if (kind == 2) {
			int id;
			scanf("%d",&id);
			printf("Case %d: 2 %d\n",i,id);
			if (roomCnt[id] == 0 && roomScore[id] == 0) {
				printf("NA\n");
			}
			else {
				printf("%d %d\n",roomCnt[id], roomScore[id]);
			}
		}
		else if (kind == 3) {
			int time;
			scanf("%d",&time);
			printf("Case %d: 3 %06d\n",i,time);
			for (int j=0;j<1000;j++) {
				c[j].cnt = 0;
				c[j].id = j;
			}
			for (int j=0;j<n;j++) {
				if (d[j].time == time) {
					c[d[j].roomId].cnt++;
				}
			}
			sort(c,c+1000);
			int j;
			for (j=0;j<1000;j++) {
				if (c[j].cnt == 0) {
					break;
				}
				printf("%d %d\n",c[j].id, c[j].cnt);
			}
			if (j == 0) {
				printf("NA\n");
			}
		}
	}
	return 0;
}
