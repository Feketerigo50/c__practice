class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slots = 1;
        int length = preorder.size();
        int index = 0;

        while(index < length){
            if(preorder[index] == ','){
                index++;
            }

            slots--;
            if(slots < 0) return false;

            if(preorder[index] == '#'){
                index++;
            }else{
                while(preorder[index] != ','){
                    index++;
                    if(index == length) break;
                }
                slots += 2;
            }
        }

        return slots == 0;
    }
};