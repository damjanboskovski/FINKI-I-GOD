#include <stdio.h>

int main(){
    int n,m, cnt=0; scanf("%d %d", &n, &m); int arr[n][m];

    for(int i=0; i<n; i++){ for(int j=0; j<m; j++){ scanf("%d", &arr[i][j]); } }

    for(int i = 0; i<n; i++){ int flag = 0;
        for(int j=0; j<m; j++){
            flag++; if(arr[i][j] == 0){ flag = 0; }
            if(flag == 3){ cnt++; break;}
        }
    }

    for(int j = 0; j<m; j++){ int flag = 0;
        for(int i=0; i<n; i++){
            flag++; if(arr[i][j] == 0){ flag = 0; }
            if(flag == 3){ cnt++; break;}
        }
    }

    printf("%d", cnt);
}