#include <iostream>
#include <vector>
using namespace std;
 
struct Atom{
    int x;
    int y;
    int dir;
    int energy;
};
 
int N;
 
vector<Atom> atoms;
int map[4001][4001];

const int dy[] = { 1, -1, 0, 0 };
const int dx[] = { 0, 0, -1, 1 };

int answer;

int calcTotalEnergy(){
    int totalEnergy = 0;
    while(!atoms.empty()){
        int size = atoms.size();
        for(int i = 0; i < size; i++){
            map[atoms[i].y][atoms[i].x] = 0;
            int dir = atoms[i].dir;
            int ny = atoms[i].y + dy[dir];
            int nx = atoms[i].x + dx[dir];
            if(nx < 0 || nx > 4000 || ny < 0 || ny > 4000) {
                atoms[i].energy = 0;
                continue;
            }
            atoms[i].y = ny;
            atoms[i].x = nx;
            map[ny][nx] += atoms[i].energy;
        }
        for(int i = 0; i < size; ++i){
            if(atoms[i].energy == 0)    continue;
            int y = atoms[i].y;
            int x = atoms[i].x;
            if(map[y][x] != atoms[i].energy){
                totalEnergy += map[y][x];
                map[y][x] = 0;
                atoms[i].energy = 0;
            }
        }

        vector<Atom> tempVector;
        tempVector.assign(atoms.begin(), atoms.end());
        atoms.clear();
        for(int i = 0; i < tempVector.size(); ++i){
            if(tempVector[i].energy != 0){
                atoms.push_back(tempVector[i]);
            }
        }
    }
    return totalEnergy;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; ++tc){
        cin >> N;
        for(int i = 0; i < N; ++i){
            Atom atom;
            cin >> atom.x >> atom.y >> atom.dir >> atom.energy;
            atom.y = (atom.y + 1000) * 2;
            atom.x = (atom.x + 1000) * 2;
            atoms.push_back(atom);
        }
        cout << "#" << tc << " " << calcTotalEnergy() << "\n";
    }
    return 0;
}