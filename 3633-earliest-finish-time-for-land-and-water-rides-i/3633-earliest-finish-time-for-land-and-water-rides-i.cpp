class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(), k = waterStartTime.size();
        int cta=INT_MAX;
        for(int i=0; i<n; i++){
            int tr = landStartTime[i]+landDuration[i];
            if(tr < cta){
                cta = tr;
            }
        }
        int tr=INT_MAX;
        for(int i=0; i<k; i++){
            if(waterStartTime[i]<=cta) tr=min(tr,waterDuration[i]);
            else{
                tr = min(tr,waterStartTime[i]-cta+waterDuration[i]);
            }
        }
        cta+=tr;
        int ctb=INT_MAX;
        for(int i=0; i<k; i++){
            int tr = waterStartTime[i]+waterDuration[i];
            if(tr < ctb){
                ctb = tr;
            }
        }
        tr=INT_MAX;
        for(int i=0; i<n; i++){
            if(landStartTime[i]<=ctb) tr=min(tr,landDuration[i]);
            else{
                tr = min(tr,landStartTime[i]-ctb+landDuration[i]);
            }
        }
        ctb+=tr;
        return min(cta,ctb);
    }
};