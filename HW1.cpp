#include<iostream>
#include<stack>
using namespace std;

class element//座標、方向
{
    public:
        int vert;
        int horiz;
        int dir;
};

class direct//儲存方向走法
{
    public:
        int vert;
        int horiz;
};

int main()
{
    //方向陣列
    direct move[4];
    move[0].vert = -1; move[0].horiz = 0; move[1].vert = 0; move[1].horiz = 1; move[2].vert = 1; move[2].horiz = 0;move[3].vert = 0; move[3].horiz = -1;
    //幾列  幾行  現在座標  下一個座標  方向  stack大小    
    int rowNum, colNum, row, col, nextRow, nextCol, dir, top;
    bool found = false;
    element position;
    stack<element> path;
    cin >> rowNum;
    cin >> colNum;
    int maze[rowNum+2][colNum+2];
    int mark[rowNum+2][colNum+2] ;
    int exitRow = rowNum; int exitCol = colNum;

    //初始迷宮
    for(int i = 0; i < rowNum +2; i++){
        for(int j = 0; j < colNum +2; j++){
            maze[i][j] = 1;
            mark[i][j] = 1;
        }
    }

    for(int i = 1; i < rowNum +1; i++){
        for(int j = 1; j < colNum +1; j++){
            int tmp;
            cin >> tmp;
            maze[i][j] = tmp;
            mark[i][j] = tmp;
        }
    }
    position.horiz = 1; position.vert = 1; position.dir = 0;
    mark[1][1] = 1; top = 0; path.push(position);

    //找路徑
    while(top > -1 && !found){
        
        position = path.top();
        top--;
        path.pop();
        row = position.vert; col = position.horiz; dir = position.dir;
        while(dir < 4 && !found){

            nextRow = row + move[dir].vert;
            nextCol = col + move[dir].horiz;
            if(nextRow == exitRow && nextCol == exitCol){
                
                found = true;
                position.vert = row; position.horiz = col;
                position.dir = ++dir;
                path.push(position);
                row = nextRow; col = nextCol; dir = 0;
                top++;
                position.vert = row; position.horiz = col;
                position.dir = ++dir;
                path.push(position);
                break;
            }
            else if(!maze[nextRow][nextCol] && !mark[nextRow][nextCol]){
                mark[nextRow][nextCol] = 1;
                position.vert = row; position.horiz = col;
                position.dir = ++dir;
                path.push(position);
                row = nextRow; col = nextCol; dir = 0;
                top++;
            }
            else{
                ++dir;
            }
        }
    }

    //最後輸出結果
    if(found){
        
        stack<element> reverse;
        while(!path.empty()){
        
            reverse.push(path.top());
            path.pop();
        }
        while(!reverse.empty()){
            element TMP = reverse.top();
            reverse.pop();
            cout << "(" << TMP.vert - 1 << "," << TMP.horiz - 1 << ") ";
        }
    }
    else{
        cout << "Can't reach the exit!" << endl;
    }

}