/*
题目描述
  把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序
  的数组的一个旋转，输出旋转数组的最小元素。 
  
例如:
  数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
  
NOTE：
  给出的所有元素都大于0，若数组大小为0，请返回0。
*/
//author = Qiufeng

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        
        int temp = 0;
        if(rotateArray.size() == 0)
        {
            return 0;
        }
        else{
            for(int i = 1;i < rotateArray.size();i++)
            {
                if(rotateArray[i-1]>rotateArray[i])
                {
                    temp = i;
                    break;
                    //break;
                }
                else
                    continue;
            }
        }
/*
        vector<int> newVector;
        for(int i = temp;i<rotateArray.size();i++)
        {
            newVector.push_back(rotateArray[i]);
        }
        
        for(int i = 0;i<temp;i++)
        {
            newVector.push_back(rotateArray[i]);
        }
        */
        return rotateArray[temp];    //如果在循环中直接return ,牛客网的编译器会报错。所以，一般结果放在最后return.
    }
};
