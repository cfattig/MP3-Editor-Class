/***************************************************************************//**
 *@file
 *
 *@brief cpp file for basic functions that do not need access to the mp3Editor
 * class
 ******************************************************************************/

#pragma pack(1)
#include "functions.h"

/***************************************************************************//**
 * @author Jeffrey Ross
 *
 * @par Description:
 * This function prints all the options to the screen.
 *
 * @returns nothing
 *
 ******************************************************************************/
void displayMenu()
{
    cout << "\n\n\n";
    cout << "Editor Choices" << endl;
    cout << "1 ) Edit song title" << endl;
    cout << "2 ) Edit artist name" << endl;
    cout << "3 ) Edit album name" << endl;
    cout << "4 ) Edit album year" << endl;
    cout << "5 ) Edit comment" << endl;
    cout << "6 ) Edit album track" << endl;
    cout << "7 ) Edit genre" << endl;
    cout << "8 ) Play song" << endl;
    cout << "9 ) Save changes" << endl;
    cout << "10) Next file" << endl;
    cout << "11) Swap contents of files" << endl;
    cout << "12) Copy contents of another mp3" << endl;
    cout << "13) Change genre field of multiple mp3s" << endl;
    cout << "\nEnter Choice: ";
}



/***************************************************************************//**
 * @author Jeffrey Ross
 *
 * @par Description:
 * This function takes the choice that the user picks from the menu and
 * performs the selected option. This is done using a switch statement for the
 * variable choice.
 *
 * @param[in] choice - The option that the user selected
 * @param[in] mp3 - the class containg the mp3 details
 * @param[in] fout - the mp3 file to make changes to
 * @param[in] name - the name of the mp3 file
 *
 * @returns nothing
 *
 ******************************************************************************/
void pickChoice(int choice, mp3Editor &mp3, ofstream &fout, char* name)
{
    string temp;
    int temp2;
    cin.ignore();
    switch (choice)
    {
    case 1: cout << "Enter song title: ";
        getline(cin, temp);
        mp3.setSongTitle(temp);
        break;
    case 2: cout << "Enter artist name: ";
        getline(cin, temp);
        mp3.setArtistName(temp);
        break;
    case 3: cout << "Enter album name: ";
        getline(cin, temp);
        mp3.setAlbumName(temp);
        break;
    case 4: cout << "Enter album year: ";
        getline(cin, temp);
        mp3.setYear(temp);
        break;
    case 5: cout << "Enter comment: ";
        getline(cin, temp);
        mp3.setComment(temp);
        break;
    case 6: cout << "Enter album track number: ";
        cin >> temp2;
        mp3.setTrack((char &)temp2);
        break;
    case 7: displayGenres();
        cout << "Enter genre number: ";
        cin >> temp2;
        mp3.setGenre((char &)temp2);
        break;
    case 8: play(name);
        break;
    case 9: fout << mp3;
        break;
    case 10: break;
    case 11: cout << "Enter mp3 file name to swap with: ";
        getline(cin, temp);
        mp3.swap(mp3, temp);
        break;
    case 12: cout << "Enter mp3 file name to copy from: ";
        getline(cin, temp);
        mp3.copy(mp3, temp);
        break;
    case 13: massAlbum();
        break;
    }
}



/***************************************************************************//**
 * @author Bailey Ezra Thorson
 *
 * @par Description:
 * This function displays all the genres from the file genres.bin file to the 
 * screen.
 *
 * @returns void
 *
 ******************************************************************************/
void displayGenres()
{
	int i;
    int count = 1;
	ifstream genre;
	char buffer[30];

	genre.open("genres.bin");
	if (!genre.is_open())
	{
		cout << "Could not find Genres.bin, exiting program" << endl;
		exit(1);
	}
	for (i = 0; i < 148; i++)
	{
		genre.seekg(i * 30, ios::beg);
		genre.read((char*)buffer, 30);
        cout << setw(3) << right << i << ") ";
        cout << setw(23) << left << buffer;
        if (count == 4)
        {
            cout << endl;
            count = 0;
        }
        count++;
	}
    cout << endl;
}



/***************************************************************************//**
 * @author Christian Fattig
 *
 * @par Description:
 * This function combines both the paths for Windows Media Player and for
 * the directory for the current file. This combined string is then put into
 * the system function which will play it for the user.
 *
 * @param[in] name - stores the name of the current mp3 file.
 *
 ******************************************************************************/
void play(char* name)
{
	
	char mp3[250];//holds the path to the current directory
	// will hold the entire string 
	char full[500] = "\"\"c:\\Program Files (x86)\\Windows Media Player\\wmplayer.exe\" \"";


	_getcwd(mp3, 250);//fill mp3 with current directory path

	//combines the paths
	strcat(full, mp3);
	strcat(full, "\\");
	strcat(full, name);
	strcat(full, "\"\"");

	cout << "Paths: " << full << endl;
	system(full);//plays the song

	return;
}

void massAlbum()
{
    mp3Editor mp1;
    string temp;
    string temp2;
    ifstream fin;
    ofstream fout;
    cout << "Enter album name to be added: ";
    getline(cin, temp);
    cout << endl << "When finished, enter 0 for mp3 file name" << endl;
    while (temp2 != "0")
    {
        int check = 0;
        cout << "Enter an mp3 file name: ";
        getline(cin, temp2);
        fin.open(temp2, ios::in | ios::binary);
        if (!fin.is_open())
        {
            cout << "could not open file" << endl;
            check = 1;
        }
        if (check != 1)
        {
            fin >> mp1;
            fin.close();
            fout.open(temp2, ios::in | ios::out | ios::binary);
            if (!fout.is_open())
            {
                cout << "could not open file" << endl;
                check = 2;
            }
            if (check != 2)
            {
                mp1.setAlbumName(temp);
                fout << mp1;
                cout << "Change successful!" << endl;
            }
        }
    }
}