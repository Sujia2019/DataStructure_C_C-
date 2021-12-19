#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100
typedef char VertexType;  // 顶点的数据类型
typedef int EdgeType;     // 带权图中边上权值的数据类型
typedef struct{
    VertexType Vex[MaxVertexNum];               // 顶点表
    EdgeType Edge[MaxVertexNum][MaxVertexNum];  // 邻接矩阵，边表 bool(0或∞表示两点不存在边)
    int vexNum,arcNum;                          // 图的当前顶点数和边数/弧树
}MGraph;

// 用邻接表存储的图
typedef struct{
    AdjList vertices;
    int vexNum,arcNum;
}ALGraph;

// “顶点”
typedef struct VNode{
    VertexType data;            // 顶点信息
    // ArcNode
}VNode,AdjList[MaxVertexNum];
// “边/弧”
typedef struct ArcNode{
    int adjVex;                 // 边/弧指向哪个结点
    struct ArcNode *next;       // 指向下一条弧的指针
    // InfoType info            // 边权值
}ArcNode;                       

// 十字链表法 存储有向图
typedef struct TenNode{
    EdgeType data;
    HU *firstin;   // 该顶点作为弧头的第一条弧
    HU *firstout;  // 该顶点作为弧尾的第一条弧
}TenNode,TenList[MaxVertexNum];
// HU
typedef struct HU{
    int tailVex;   // 弧头顶点编号
    int headVex;   // 弧尾顶点编号
    HU *hLink;     // 弧头相同的下一条弧
    HU *tLink;     // 弧尾相同的下一条弧
    int info;      // 权值
}HU;

// 邻接多重表 存储无向图
// 顶点结点
typedef struct ALGraph2{
    EdgeType data;
    BIAN  *firstEdge; // 与该顶点相连的第一条边
}ALGraph2;
typedef struct BIAN{
    int i;
    int j;            // 边的两个顶点编号i，j
    int info;         // 权值
    BIAN *iLink;      // 依附于顶点i的下一条边
    BIAN *jLink;      // 依附于顶点j的下一条边
}BIAN;

// BFS
// bool visited[MaxVertexNum];      // 访问标记数组
// void BFSTraverse(Graph G){   
//     for(i=0;i<G.vexNum;++i){
//          visited[i]=FALSE;       // 访问标记数组初始化
//     }
//     InitQueue(Q);                // 初始化辅助队列Q
//     for(i=0;i<G.vexNum;++i)      // 从0号顶点开始遍历
//         if(!visited[i])          // 对每个连通分量调用一次BFS
//             BFS(G, i);           // vi未访问过，从vi开始BFS
// }
// void BFS(Graph G, int v){        // 从顶点v出发，广度优先遍历图G
//     visit(v);                    // 访问初始顶点v
//     visited[v]=TRUE;             // 对v做已访问标记
//     EnQueue(Q,v);                // 顶点v入队列Q
//     while(!isEmpty(Q)){
//         DeQueue(Q,v);            // 顶点v出队列
//         for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w)){
                // 检测v所有邻接点
//              if(!visited[w]){    // w为v的尚未访问的邻接顶点
//                  visit(w);       // 访问顶点w
//                  visited[w]=TRUE;// 对w做已访问标记
//                  EnQueue(Q,w);   // 顶点w入队列
//              }
//         }
//     }
// }