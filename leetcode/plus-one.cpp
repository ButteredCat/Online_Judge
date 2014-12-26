class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry=0;
        vector<int>::reverse_iterator iv = digits.rbegin();
        if(*iv+1>9) {
            *iv=0;
            carry=1;
        }
        else {
            *iv+=1;
        }
        for(++iv; iv != digits.rend(); ++iv) {
            if(*iv+carry>9) {
                *iv=0;
                carry=1;
            }
            else {
                *iv+=carry;
                carry=0;
            }
        }
        if(carry==1) {
            digits.insert(digits.begin(),carry);
        }

        return digits;
    }
};