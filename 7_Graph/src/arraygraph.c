# include "../include/arraygraph.h"

void* graphFree(ArrayGraph* pGraph) {
    if (pGraph->ppAdjEdge != NULL) {
        free(pGraph->ppAdjEdge);
        pGraph->ppAdjEdge = NULL;
    }
    if (pGraph->pVertex != NULL) {
        free(pGraph->pVertex);
        pGraph->pVertex = NULL;
    }
    if (pGraph != NULL) {
        free(pGraph);
        pGraph = NULL;
    }
    return NULL;
}

// 그래프 생성
ArrayGraph* createArrayGraph(int maxVertexCount){
    ArrayGraph *pGraph = NULL;

    if (maxVertexCount <= 0) return NULL;

    pGraph = (ArrayGraph *)calloc(1, sizeof(ArrayGraph));
    if (!pGraph) return graphFree(pGraph);
    pGraph->graphType = GRAPH_UNDIRECTED;
    pGraph->maxVertexCount = maxVertexCount;

    pGraph->pVertex = (int *)calloc(maxVertexCount, sizeof(int));
    if(!pGraph->pVertex) return graphFree(pGraph);
    
    pGraph->ppAdjEdge = (int **)calloc(maxVertexCount, sizeof(int**));
    if (!pGraph->ppAdjEdge) return graphFree(pGraph);
    
    for (int i = 0; i < maxVertexCount; i++) {
        pGraph->ppAdjEdge[i] = (int *)calloc(maxVertexCount, sizeof(int));
        if (!pGraph->ppAdjEdge[i]) {
            for (int j = 0; j < i - 1; j++) {
                if (pGraph->ppAdjEdge[i] != NULL) {
                    free(pGraph->ppAdjEdge[j]);
                    pGraph->ppAdjEdge[j] = NULL;
                }
            }
            return (graphFree(pGraph));
        }
    }
    return pGraph;
}

ArrayGraph* createArrayDirectedGraph(int maxVertexCount){
    ArrayGraph *pGraph = NULL;

    pGraph = createArrayGraph(maxVertexCount);
    if (pGraph != NULL) pGraph->graphType = GRAPH_DIRECTED;

    return pGraph;
}

// 공백 그래프 여부 판단
int isEmptyAG(ArrayGraph* pGraph){
    return (pGraph != NULL && pGraph->currentVertexCount > 0 ? FALSE : TRUE);
}

// 노드 추가
int addVertexAG(ArrayGraph* pGraph, int vertexID){
    if (!pGraph 
        || vertexID >= pGraph->maxVertexCount 
        || pGraph->pVertex[vertexID] == USED) 
        return FAIL;

        pGraph->pVertex[vertexID] = USED;
        pGraph->currentVertexCount++;
        return SUCCESS;
}

// 간선 추가
int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID){
    addEdgewithWeightAG(pGraph, fromVertexID, toVertexID, USED);
}

int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight){
    if (!pGraph 
        || checkVertexValid(pGraph, fromVertexID) == FAIL 
        || checkVertexValid(pGraph, toVertexID) == FAIL)
        return FAIL;
    pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;

    if (pGraph->graphType == GRAPH_UNDIRECTED) 
        pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
    return SUCCESS;
}

// 노드의 유효성 검사
int checkVertexValid(ArrayGraph* pGraph, int vertexID){
    if (vertexID >= pGraph->maxVertexCount 
        || pGraph->pVertex[vertexID] == NOT_USED) 
        return FAIL;

    return SUCCESS;
}

// 간선 제거
int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID){
    if (!pGraph 
        || checkVertexValid(pGraph, fromVertexID) == FAIL 
        || checkVertexValid(pGraph, toVertexID) == FAIL) 
        return FAIL;
    pGraph->ppAdjEdge[fromVertexID][toVertexID] = 0;
    if (pGraph->graphType == GRAPH_UNDIRECTED) 
        pGraph->ppAdjEdge[toVertexID][fromVertexID] = 0;

    return SUCCESS;
}

// 노드 제거
int removeVertexAG(ArrayGraph* pGraph, int vertexID){
    if (!pGraph 
        || checkVertexValid(pGraph, vertexID) == FAIL) 
        return FAIL;
    for (int i = 0; i < pGraph->maxVertexCount; i++){
        removeEdgeAG(pGraph, vertexID, i);
        removeEdgeAG(pGraph, i, vertexID);
    }
    pGraph->pVertex[vertexID] = NOT_USED;
    return SUCCESS;
}

// 그래프 삭제
void deleteArrayGraph(ArrayGraph* pGraph){
    if (pGraph != NULL) {
        for (int i = 0; i< pGraph->maxVertexCount; i++){
            free(pGraph->ppAdjEdge[i]);
        }
        free(pGraph->ppAdjEdge);
        free(pGraph->pVertex);
        free(pGraph);
    }
}

// 그래프 정보 출력
void displayArrayGraph(ArrayGraph* pGraph){
    if (pGraph != NULL) {
        for (int i = 0; i < pGraph->maxVertexCount; i++){
            for (int j = 0; j < pGraph->maxVertexCount; j++){
                printf(" [%d] ", pGraph->ppAdjEdge[i][j]);
            }
            printf("\n");
        }
    }
}