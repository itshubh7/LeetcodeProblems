class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int distance1=0, distance2=0;
        if(start>destination)
        {
            start = start ^ destination;
            destination = start ^ destination;
            start = start ^ destination;
        }
        for(int i=start; i<destination; i++)
        {
            distance1 += distance[i];
        }
        for(int i=destination; i<distance.size(); i++)
        {
            distance2 += distance[i];
        }
        for(int i=0; i<start; i++)
        {
            distance2 += distance[i];
        }
        return min(distance1, distance2);
    }
};