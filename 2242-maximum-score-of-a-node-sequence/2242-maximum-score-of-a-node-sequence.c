int maximumScore(int* scores, int scoresSize, int** edges, int edgesSize, int* edgesColSize) {
    int edgeMap[scoresSize][3];
    memset(edgeMap,-1,scoresSize*12);
    for (int i=0;i<edgesSize;i++){
        if (edgeMap[edges[i][1]][1]==-1 || scores[edges[i][0]]>scores[edgeMap[edges[i][1]][1]]){//placing edges[i][0]
            edgeMap[edges[i][1]][2]=edgeMap[edges[i][1]][1];
            if (edgeMap[edges[i][1]][0]==-1 || scores[edges[i][0]]>scores[edgeMap[edges[i][1]][0]]){
                edgeMap[edges[i][1]][1]=edgeMap[edges[i][1]][0];
                edgeMap[edges[i][1]][0]=edges[i][0];
            }
            else edgeMap[edges[i][1]][1]=edges[i][0];
        }
        else if (edgeMap[edges[i][1]][2]==-1 || scores[edges[i][0]]>scores[edgeMap[edges[i][1]][2]]){
            edgeMap[edges[i][1]][2]=edges[i][0];
        }
        if (edgeMap[edges[i][0]][1]==-1 || scores[edges[i][1]]>scores[edgeMap[edges[i][0]][1]]){//placing edges[i][1]
            edgeMap[edges[i][0]][2]=edgeMap[edges[i][0]][1];
            if (edgeMap[edges[i][0]][0]==-1 || scores[edges[i][1]]>scores[edgeMap[edges[i][0]][0]]){
                edgeMap[edges[i][0]][1]=edgeMap[edges[i][0]][0];
                edgeMap[edges[i][0]][0]=edges[i][1];
            }
            else edgeMap[edges[i][0]][1]=edges[i][1];
        }
        else if (edgeMap[edges[i][0]][2]==-1 || scores[edges[i][1]]>scores[edgeMap[edges[i][0]][2]]){
            edgeMap[edges[i][0]][2]=edges[i][1];
        }
    }
    int output=-1;
    for (int i=0;i<edgesSize;i++){
        int sum=scores[edges[i][0]]+scores[edges[i][1]];
        int left=(edgeMap[edges[i][0]][0]==edges[i][1]);
        int right=(edgeMap[edges[i][1]][0]==edges[i][0]);
        if (edgeMap[edges[i][0]][left]==-1 || edgeMap[edges[i][1]][right]==-1){
            continue;
        }
        if (edgeMap[edges[i][0]][left]!=edgeMap[edges[i][1]][right]){
            sum+=scores[edgeMap[edges[i][0]][left]]+scores[edgeMap[edges[i][1]][right]];
        }
        else{
            int left2=left+1+(edgeMap[edges[i][0]][left+1]==edges[i][1]);
            int right2=right+1+(edgeMap[edges[i][1]][right+1]==edges[i][0]);
            if (edgeMap[edges[i][0]][left2]==-1 && edgeMap[edges[i][1]][right2]==-1){
                continue;
            }
            if (edgeMap[edges[i][1]][right2]!=-1 && (edgeMap[edges[i][0]][left2]==-1 || scores[edgeMap[edges[i][1]][right2]]>scores[edgeMap[edges[i][0]][left2]])){
                sum+=scores[edgeMap[edges[i][0]][left]]+scores[edgeMap[edges[i][1]][right2]];
            }
            else sum+=scores[edgeMap[edges[i][0]][left2]]+scores[edgeMap[edges[i][1]][right]];
        }
        output=(sum>output?sum:output);
    }
    return output;
}