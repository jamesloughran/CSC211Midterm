#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class NBAPlayer{

    private:
        
        string name;
        string team;
        double ppg;
        double apg;
        double rpg;
        double fgp;
        double tpp;
        int ID;

    public:
        // all class functions
        void setID(int);
        void addPlayer();
        void loadPlayersFromFile(ifstream &);
        void editStat();
        void printPlayer();
        string printTeam();
        void printPlayersList(vector<NBAPlayer>);
        void printTheTeams();
        void savePlayersToFile(ofstream&);

};

// sets an ID for players to choose from
void NBAPlayer::setID(int id){
    ID = id;
}

// when adding player, promted the user with this
void NBAPlayer::addPlayer(){
    cout << "Enter Player's name: ";
    getline(cin, name);
    cout << "Enter Player's team: ";
    getline(cin, team);
    cout << "Enter Player's points per game: ";
    cin >> ppg;
    cout << "Enter Player's assist per game: ";
    cin >> apg;
    cout << "Enter Player's rebounds per game: ";
    cin >> rpg;
    cout << "Enter Player's field goal percentage: ";
    cin >> fgp;
    cout << "Enter Player's 3-point percentage: ";
    cin >> tpp;
    cin.ignore();
}

// reads the player from the inFile playersCOPY.txt
void NBAPlayer::loadPlayersFromFile(ifstream &inFile){
    getline(inFile, name);
    getline(inFile, team);
    inFile >> ppg;
    inFile >> apg;
    inFile >> rpg;
    inFile >> fgp;
    inFile >> tpp;
    inFile.ignore();
}

// how the players will be printed in the terminal
void NBAPlayer::printPlayer(){
    cout << left << fixed << setprecision(1);
    cout << setw(30) << name << setw(30) << team << setw(10) << ppg << setw(10) << apg << setw(10) << rpg << setw(10) << fgp << setw(10) << tpp;
    
}

// prints just the teams the players are on
void NBAPlayer::printTheTeams(){
    cout << team << endl;
}

// edit all the 5 stats
void NBAPlayer::editStat(){
    
    double newPpg;
    cout << name << "'s current PPG (Points Per Game) is: " << ppg << " Enter New PPG: " << endl;
    cin >> newPpg;
    cin.ignore();
    ppg = newPpg;

    double newApg;
    cout << name << "'s current APG(Assists Per Game) is: " << apg << " Enter New APG: " << endl;
    cin >> newApg;
    cin.ignore();
    apg = newApg;

    double newRpg;
    cout << name << "'s current RPG(Rebounds Per Game) is: " << rpg << " Enter New RPG: " << endl;
    cin >> newRpg;
    cin.ignore();
    rpg = newRpg;

    double newFgp;
    cout << name << "'s current FGP(Field Goal Percent) is: " << fgp << " Enter New FGP: " << endl;
    cin >> newFgp;
    cin.ignore();
    fgp = newFgp;

    double newTpp;
    cout << name << "'s current 3-PP(3 points percent) is: " << tpp << " Enter New 3-PP: " << endl;
    cin >> newTpp;
    cin.ignore();
    tpp = newTpp;
    
}
// helps returns the team
string NBAPlayer::printTeam(){
    return team;
}

// how the outFile will save in the inFile
void NBAPlayer::savePlayersToFile(ofstream &out){
    out << name << endl;
    out << team << endl;
    out << ppg << endl;
    out << apg << endl;
    out << rpg << endl;
    out << fgp << endl;
    out << tpp;
}
    

// gives the plays a number to choose from
void NBAPlayer::printPlayersList(vector <NBAPlayer> playerCount) {    
        for (int i = 0; i < playerCount.size(); i++){
            cout << i + 1 << ". " << playerCount.at(i).name << endl;
        }
}



int main(){

    ifstream inFile("players.txt");
    int choice;
    int x = 0;
    int playerCount = 1;
    vector<NBAPlayer> allplayers;
    NBAPlayer tempPlayer;

    vector<NBAPlayer> teamList;
    NBAPlayer tempTeam;


    if(inFile.is_open()){
        while(!inFile.eof()){
            tempPlayer.setID(playerCount);
            tempPlayer.loadPlayersFromFile(inFile);
            allplayers.push_back(tempPlayer);
            playerCount++;
        }
    }

    do{
        cout << endl;
        cout << "||============================================||" << endl;
        cout << "||------------------MENU----------------------||" << endl;
        cout << "||============================================||" << endl;
        cout << "||   1: add Player                            ||" << endl;
        cout << "||--------------------------------------------||" << endl;
        cout << "||   2: print all players                     ||" << endl;
        cout << "||--------------------------------------------||" << endl;
        cout << "||   3: Print A Single player                 ||" << endl;
        cout << "||--------------------------------------------||" << endl;
        cout << "||   4: Edit A Players Stats                  ||" << endl;
        cout << "||--------------------------------------------||" << endl;
        cout << "||   5: Print All Players On A Curtain Team   ||" << endl;
        cout << "||--------------------------------------------||" << endl;
        cout << "||   6: Save Changes                          ||" << endl;
        cout << "||--------------------------------------------||" << endl;
        cout << "||   7: Close Program                         ||" << endl;
        cout << "||============================================||" << endl;
        cout << endl;
        cout << "ENTER YOUR CHOICE: ";
        cin >> choice;
    
        cout << endl;
        cin.ignore();
        cout << endl;
        
        

        switch(choice){
            case 1:
                // add a player to the vector
                tempPlayer.setID(playerCount);
                tempPlayer.addPlayer();
                allplayers.push_back(tempPlayer);
                playerCount++;
                break;
            case 2:
                // print all the players
               cout << left << fixed << setprecision(1);
               cout << "============================================================================================================" << endl;
               cout << setw(30) << "NAME" << setw(30) << "TEAM" << setw(10) << "PPG" << setw(10) << "APG" << setw(10) << "RPG" << setw(10) << "FGP" << setw(10) << "3-PP" << endl;
               cout << "============================================================================================================" << endl;
               for(int i = 0; i < allplayers.size(); i++){
                allplayers.at(i).printPlayer();
                cout << endl;
                cout << "-----------------------------------------------------------------------------------------------------------" << endl;
                
               }
               break;

            case 3:
                // print a single player
                cout << "Pick a Player: " << endl;
                cout << endl;
                tempPlayer.printPlayersList(allplayers);
                cout << endl;
                cout << "Enter Choice: ";
                cin >> x;
                cin.ignore();
                cout << left << fixed << setprecision(1);
                cout << "============================================================================================================" << endl;
                cout << setw(30) << "NAME" << setw(30) << "TEAM" << setw(10) << "PPG" << setw(10) << "APG" << setw(10) << "RPG" << setw(10) << "FGP" << setw(10) << "3-PP" << endl;
                cout << "============================================================================================================" << endl;
                allplayers.at(x - 1).printPlayer();
                cout << endl;
                cout << "-----------------------------------------------------------------------------------------------------------" << endl;
                break;
            
            case 4:
                // Edit a players 5 stats
                cout << "Pick a Player: " << endl;
                tempPlayer.printPlayersList(allplayers);
                cout << "Enter Choice: ";
                cin >> x;
                cin.ignore();
                allplayers.at(x - 1).editStat();
                cout << "STATS EDITED";
                break;

            case 5:{
                // print a player from a Curtain Team

                // make a new vector to push all the teams
                vector<string> teamList;
                
                // make it so the teams being pushed dont print more then once
                for (int i = 0; i < allplayers.size(); i++){
                    string team = allplayers.at(i).printTeam();
                    bool isUnique = true;
                    for (int j = 0; j < teamList.size(); j++){
                        if (teamList.at(j) == team){
                            isUnique = false;
                            break;
                        }
                    }

                    if (isUnique){
                        teamList.push_back(team);
                    }
                }

                // show the user the list of teams
                cout << "Available Teams: " << endl;
                cout << endl;
                for (int i = 0; i < teamList.size(); i++){
                    cout << i + 1 << ": " << teamList.at(i) << endl;
                }
                cout << endl;

                // let the user pick a team
                cout << "Pick a Team: " << endl;
                int teamChoice;
                cin >> teamChoice;
                cin.ignore();

                // if the user dont put the choice tell the user "that choice is not avaiable"
                if(teamChoice < 1 || teamChoice > teamList.size()){
                    cout << "CHOICE NOT AVAIABLE" << endl;
                    break;
                }

                string selectedTeam = teamList.at(teamChoice - 1);

                cout << left << fixed << setprecision(2);
                cout << "============================================================================================================" << endl;
                cout << setw(30) << "NAME" << setw(30) << "TEAM" << setw(10) << "PPG" << setw(10) << "APG" << setw(10) << "RPG" << setw(10) << "FGP" << setw(10) << "3-PP" << endl;
                cout << "============================================================================================================" << endl;

                // print all the players on the team selected
                for (int i = 0; i < allplayers.size(); i++) {
                    NBAPlayer& player = allplayers.at(i); // Reference to the current player
                    if (player.printTeam() == selectedTeam) {
                        player.printPlayer(); // Print player information if they belong to the specified team
                        cout << endl;
                        cout << "-----------------------------------------------------------------------------------------------------------" << endl;
                    }
                }
                break;
                

            }
            case 6:{
                // saves the file into players.txt
                ofstream outFile;

                outFile.open("players.txt");

                if(outFile.fail()){
                    cerr << "File failed to open";
                    abort();
                }

                cout << "Saving Data to file" << endl;
                for(int i = 0; i <allplayers.size(); i++){
                    if(i == allplayers.size() - 1){
                        allplayers.at(i).savePlayersToFile(outFile);
                    }
                    else{
                        allplayers.at(i).savePlayersToFile(outFile);
                        outFile << endl;
                    }
                }
                cout << "SAVE COMPLETE" << endl;
                outFile.close();
                break;
            }

            case 7:
                cout << "EXITING" << endl;
                break;

            default:
                cout << "INVALID CHOICE, ENTER AGAIN" << endl;
                break;
        }
        
    }while (choice != 7);
    return 0;// hi
}