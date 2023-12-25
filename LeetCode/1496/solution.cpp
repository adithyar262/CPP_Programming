/*
1496. Path Crossing

Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.

Return true if the path crosses itself at any point, that is, if at any time you are on a location you have previously visited. Return false otherwise.

Example 1:


Input: path = "NES"
Output: false 
Explanation: Notice that the path doesn't cross any point more than once.
Example 2:


Input: path = "NESWW"
Output: true
Explanation: Notice that the path visits the origin twice.
 

Constraints:

1 <= path.length <= 104
path[i] is either 'N', 'S', 'E', or 'W'.

*/

#include <unordered_map>
typedef struct paths{
    int x;
    int y;
} ;

class Solution {
public:
    int maxVer = 0, maxHor = 0;
    int posHor = 0, posVer = 0;
    unordered_map<int, struct paths> pathway; 
    void updatePosHor(char dir) {
        if(dir == 'E')
            posHor ++;
        else
            posHor--;
        
        if(abs(posHor) > abs(maxHor))
            maxHor = posHor;
    }
    void updatePosVer(char dir) {
        if(dir == 'N')
            posVer ++;
        else
            posVer--;
        
        if(abs(posVer) > abs(maxVer))
            maxVer = posVer;
    }
    bool isPathCrossing(string path) {

        pathway[0] = {0, 0};
        for(int i = 0; i < path.length(); ++i) {
            if(path[i] == 'N' || path[i] == 'S')
                updatePosVer(path[i]);
            else if (path[i] == 'W' || path[i] == 'E')
                updatePosHor(path[i]);
            unordered_map<int, struct paths>:: iterator p;  
            for(p = pathway.begin(); p != pathway.end(); p++) {
                if(p->second.x == posHor && p->second.y == posVer) {
                    return true;
                }
            }
            pathway[i+1] = {posHor, posVer}; 
        }
        return false;
    }
};
