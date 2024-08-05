class Solution {
public:
    int cover(TreeNode* root, int &cam){
        if(root==NULL) return 1;

        int left = cover(root->left, cam); 
        int right = cover(root->right, cam);

         if(left==0 || right==0) 
        {
            cam++;
            return 2;
        }

        else if(left==2 || right==2) {
            return 1;
        }

        return 0; 

    }
    int minCameraCover(TreeNode* root) {
        int cam = 0;
        int miniCam = cover(root, cam);
        
        if(miniCam==0) 
            cam++;
        
        return cam;
    }
};