class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i = 0;
        vector<string> res;
        while(i<words.size()){
            string row;
            int wordNum = 0,wordWidth = 0;
            while(i<words.size()&&wordWidth+words[i].size()<= maxWidth){
                wordNum++;
                wordWidth+=words[i].size()+1;
                i++;
            }
            if(wordNum == 1){
                row+=words[i-wordNum];
                for(int j = row.size();j<maxWidth;j++)
                    row+=' ';
            }else{
                if(i == words.size()){
                    for(int j = i-wordNum;j<i;j++){
                        row+=words[j];
                        if(row.size()<maxWidth)
                            row+=' ';
                    }
                    for(int j = row.size();j<maxWidth;j++)
                        row+=' ';
                }else{
                    int maxBlank = maxWidth-wordWidth+wordNum;
                    int blankNum = wordNum-1;
                    int more = maxBlank%blankNum;
                    int size = maxBlank/blankNum;
                    for(int j = i-wordNum;j<i;j++){
                        row+=words[j];
                        for(int k = 0;row.size()<maxWidth&&k<size;k++)
                            row+=' ';
                        if(more){
                            row+=' ';
                            more--;
                        }
                    }
                }
            }
            res.push_back(row);
        }
        return res;
    }
};