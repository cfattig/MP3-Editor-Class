/***************************************************************************//**
 *@file
 *
 *@brief file containing all the functions that have access to the mp3Editor
 * class
 ******************************************************************************/

#pragma pack(1)
#include "mp3Editor.h"


/**************************************************************************//**
 * @author Bailey Ezra Thorson
 *
 * @par Description:
 *	This does not need to do anything to destroy the object
 *
 *****************************************************************************/
mp3Editor::mp3Editor()
{

}



/**************************************************************************//**
 * @author Bailey Ezra Thorson
 *
 * @par Description:
 *	This does not need to do anything to destroy the object
 *
 *****************************************************************************/
mp3Editor::~mp3Editor()
{

}



/**************************************************************************//**
 * @author Bailey Ezra Thorson
 *
 * @par Description:
 *	Edits the title stored in the MP3Tag structure
 *
 * @param[in]     mp3E - the structure to be copied
 *
 * @returns
 *
 *****************************************************************************/
mp3Editor::mp3Editor(mp3Editor &mp3E)
{
    theTags = mp3E.theTags;	//Assign passed structure's data to new structure
    return;
}



/**************************************************************************//**
 * @author Bailey Ezra Thorson
 *
 * @par Description:
 *	Edits the title stored in the MP3Tag structure
 *
 * @param[in]     s - string containing the new song title
 *
 * @returns
 *
 *****************************************************************************/
void mp3Editor::setSongTitle(string &s)
{
    int i;
    int term;        //where the c string is terminated
    char buffer[31];
    strncpy(buffer, s.c_str(), 30);
    // set all characters after \0 to \0
    term = findNullTerminator(buffer, 31);
    if (term != -1)
        for (i = term; i < 31; i++)
            buffer[i] = '\0';
    strncpy(theTags.songTitle, buffer, 30);
}



/***************************************************************************//**
 * @author Christian Fattig
 *
 * @par Description:
 * This function calls the function edit to change the artistName field to the
 * value provided by s
 *
 * @param[in] s - The string containing the new Artists Name
 *
 ******************************************************************************/
void mp3Editor::setArtistName(string &s)
{
    edit(theTags.artistName, 30, s);
}



/***************************************************************************//**
 * @author Christian Fattig
 *
 * @par Description:
 * This function calls the function edit to change the albumName field to the
 * value provided by s
 *
 * @param[in] s - The string containing the new Album Name
 *
 ******************************************************************************/
void mp3Editor::setAlbumName(string &s)
{
    edit(theTags.albumName, 30, s);
}



/***************************************************************************//**
 * @author Christian Fattig
 *
 * @par Description:
 * This function calls the function edit to change the comment field to the
 * value provided by s
 *
 * @param[in] s - The string containing the new comment
 *
 ******************************************************************************/
void mp3Editor::setComment(string &s)
{
    edit(theTags.albumName, 28, s);
}



/***************************************************************************//**
 * @author Christian Fattig
 *
 * @par Description:
 * This function calls the function edit to change the year field to the
 * value provided by s
 *
 * @param[in] year - The string containing the new Year
 *
 ******************************************************************************/
void mp3Editor::setYear(string &year)
{
    edit(theTags.year, 4, year);
}



/***************************************************************************//**
 * @author Christian Fattig
 *
 * @par Description:
 * This function checks the track number provided to it for a valid range and 
 * if it is valid, sets the track field to that new value. If it is invalid, it 
 * will simply return.
 *
 * @param[in] track - The character containing the new track number
 *
 ******************************************************************************/
void mp3Editor::setTrack(char &track)
{
	if (track <= 0 || track > 255)//checks that the number is valid
		cout << "Invalid choice, track number was not changed." << endl;
	else
		theTags.track = track;//changes the number

	return;
}



/***************************************************************************//**
 * @author Christian Fattig
 *
 * @par Description:
 * Checks the character provided to ensure that it is in the valid range for
 * genres and if it is valid, changes the genre field to that value. If it is
 * invalid, it outputs an error message and returns.
 *
 * @param[in] genre - the character value of the new genre
 *
 ******************************************************************************/
void mp3Editor::setGenre(char &genre)
{
	if (genre <= 0 || genre > 147)//checks that the number is valid
		cout << "Invalid choice, genre was not changed." << endl;
	else
		theTags.genre = genre;//changes the number

	return;
}



/***************************************************************************//**
 * @author Bailey Ezra Thorson
 *
 * @par Description:
 * Extracts the song from the mp3 structure returns it
 *
 * @returns SongTitle - The title of the song
 *
 ******************************************************************************/
string mp3Editor::getSongTitle()
{
    string title = theTags.songTitle;
    return title;
}



/***************************************************************************//**
 * @author Bailey Ezra Thorson
 *
 * @par Description:
 * Extracts the artist from the mp3 structure returns it
 *
 * @returns Artist -- The songs's artist
 *
 ******************************************************************************/
string mp3Editor::getArtistName()
{
    return theTags.artistName;
}



/***************************************************************************//**
 * @author Bailey Ezra Thorson
 *
 * @par Description:
 * Extracts the albumName from the mp3 structure returns it
 *
 * @returns Album -- The songs's album
 *
 ******************************************************************************/
string mp3Editor::getAlbumName()
{
    return theTags.albumName;
}



/***************************************************************************//**
 * @author Bailey Ezra Thorson
 *
 * @par Description:
 * Extracts the comment from the mp3 structure returns it
 *
 * @returns Comment -- The songs's comment
 *
 ******************************************************************************/
string mp3Editor::getComment()
{
    return theTags.comment;
}



/***************************************************************************//**
 * @author Bailey Ezra Thorson
 *
 * @par Description:
 * Extracts the year from the mp3 structure returns it
 *
 * @returns Year - The Song's year
 *
 ******************************************************************************/
string mp3Editor::getYear()
{
    return theTags.year;
}



/***************************************************************************//**
 * @author Bailey Ezra Thorson
 *
 * @par Description:
 * Extracts the Track from the mp3 structure returns it
 *
 * @returns Track - The Song's track
 *
 ******************************************************************************/
char mp3Editor::getTrack()
{
    return theTags.track;
}



/***************************************************************************//**
 * @author Bailey Ezra Thorson
 *
 * @par Description:
 * Extracts the genre from the mp3 structure returns it
 *
 * @returns Genre - The Song's genre
 *
 ******************************************************************************/
char mp3Editor::getGenre()
{
    return theTags.genre;
}



/***************************************************************************//**
 * @author Jeffrey Ross
 *
 * @par Description:
 * This function is an overloaded operator for the == operator. It overloads it
 * so that you can compare two mp3files to check if their contents are the same
 * regarding the last 128 bits of the file.
 *
 * @param[in] mp3E - item being compared
 *
 * @returns nothing
 *
 ******************************************************************************/
bool mp3Editor::operator==(mp3Editor &mp3E)
{
    int i;
    for (i = 0; i < 30; i++)
    {
        if (theTags.songTitle[i] != mp3E.theTags.songTitle[i])
            return false;
        if (theTags.artistName[i] != mp3E.theTags.artistName[i])
            return false;
        if (theTags.albumName[i] != mp3E.theTags.albumName[i])
            return false;
        if (i < 4)
            if (theTags.year[i] != mp3E.theTags.year[i])
                return false;
        if (i < 28)
            if (theTags.comment[i] != mp3E.theTags.comment[i])
                return false;
    }
    if (theTags.track != mp3E.theTags.track)
        return false;
    if (theTags.genre != mp3E.theTags.genre)
        return false;
    return true;
}


/***************************************************************************//**
 * @author Jeffrey Ross
 *
 * @par Description:
 * This function is an overloaded operator for the != operator. It overloads it
 * so that you can compare two mp3files to check if their contents are the same
 * regarding the last 128 bits of the file.
 *
 * @param[in] mp3E - item being compared
 *
 * @returns nothing
 *
 ******************************************************************************/
bool mp3Editor::operator!=(mp3Editor &mp3E)
{
    int i;
    for (i = 0; i < 30; i++)
    {
        if (theTags.songTitle[i] == mp3E.theTags.songTitle[i])
            return false;
        if (theTags.artistName[i] == mp3E.theTags.artistName[i])
            return false;
        if (theTags.albumName[i] == mp3E.theTags.albumName[i])
            return false;
        if (i < 4)
            if (theTags.year[i] == mp3E.theTags.year[i])
                return false;
        if (i < 28)
            if (theTags.comment[i] == mp3E.theTags.comment[i])
                return false;
    }
    if (theTags.track == mp3E.theTags.track)
        return false;
    if (theTags.genre == mp3E.theTags.genre)
        return false;
    return true;
}


/***************************************************************************//**
 * @author Christian Fattig
 *
 * @par Description:
 * This function sets one mp3 structure equal to another mp3 structure. It goes
 * through and sets each field equal to it's respective field on the other file
 *
 * @param[in,out] mp3E - structure holding the mp3 file information.
 *
 ******************************************************************************/
bool mp3Editor::operator=(mp3Editor &mp3E)
{
    for (int i = 0; i < 30; i++)
    {
        theTags.songTitle[i] = mp3E.theTags.songTitle[i];
        theTags.albumName[i] = mp3E.theTags.albumName[i];
        theTags.artistName[i] = mp3E.theTags.artistName[i];
    }

    for (int i = 0; i < 28; i++)
        theTags.comment[i] = mp3E.theTags.comment[i];
    for (int i = 0; i < 4; i++)
        theTags.year[i] = mp3E.theTags.year[i];

    theTags.track = mp3E.theTags.track;
    theTags.genre = mp3E.theTags.genre;

    return true;
}



/***************************************************************************//**
 * @author Christian Fattig
 *
 * @par Description:
 * This function seeks to the last 128 bytes in the file. It then overwrites
 * those 128 bytes with the information stored in the structure. Finally, it
 * seeks back to the beginning of the file.
 *
 * @param[in,out] mp3E - structure holding the mp3 file information.
 * @param[in,out] out - holds the current mp3 file in use.
 *
 ******************************************************************************/
ofstream &operator<<(ofstream &out, mp3Editor &mp3E)
{
    out.seekp(-128, ios::end);//seeks to last 128 bytes in file
    out.write((char *)&mp3E.theTags, 128);//writes over those bytes
    return out;
}



/**************************************************************************//**
 * @author Bailey Ezra Thorson
 *
 * @par Description:
 *	Loads tags from an MP3 file to the MP3tag structure
 *
 * @param[in]     out - An open input stream to extract MP3 tags from
 * @param[out]    mp3E - An MP3tag structure to fill with tags from the stream
 *
 * @returns out - The stream that was passed into the function
 *
 *****************************************************************************/
ifstream &operator>>(ifstream &out, mp3Editor &mp3E)
{
    out.seekg(-128, ios::end);
    out.read((char*)&mp3E.theTags, sizeof(mp3E.theTags));
    return out;
}



/***************************************************************************//**
 * @author Bailey Thorson
 *
 * @par Description:
 * This function formats the contents of the mp3Tag structure and outputs it to
 * the screen. It uses the genres.bin included in the program directory to 
 * determine what genre to output to the screen.
 * 
 *
 * @param[in]     mp3E - structure holding the mp3 file information
 * @param[in,out] out - stream to output to
 *
 * @returns out - a reference to the output stream 
 *
 ******************************************************************************/
ostream &operator<<(ostream &out, mp3Editor &mp3E)
{
    ifstream genres;
    string buffer = " ";
    char genre[30] = " ";

    genres.open("genres.bin");
    if (!genres.is_open())
    {
        cout << "Could not open genres.bin" << endl;
        //return out; Unsafe version
        exit(2);
    }

    buffer.append(mp3E.theTags.songTitle, 30);

    cout << "Song: " << buffer << " by ";

    buffer.clear();
    buffer.append(mp3E.theTags.artistName, 30);

    cout << buffer << endl;
    cout << "Track | Album: \t" << (int)mp3E.theTags.track << " | ";

    buffer.clear();
    buffer.append(mp3E.theTags.albumName, 30);

    cout << buffer << endl;

    genres.seekg(mp3E.theTags.genre * 30, ios::beg);
    genres.read((char*)genre, 30);

    buffer.clear();
    buffer.append(mp3E.theTags.year, 4);

    cout << "Genre: " << genre;
    cout << "\tYear: " << buffer << endl;

    buffer.clear();
    buffer.append(mp3E.theTags.comment, 28);

    cout << "Comment: " << buffer << endl << endl;

    genres.close();

    return out;
}



/***************************************************************************//**
 * @author Jeffrey Ross
 *
 * @par Description:
 * A function that simply swaps the contents of the last 128 bits of mp3 files.
 * it takes the name of the file that is passed in in string and brings that
 * into an mp3 structure. It swaps with the provided mp3 structure and saves
 * to file the mp3 file depicted by string, but does not save mp1.
 * 
 *
 * @param[in] mp1 - mp3 file contents to be swapped with contents of string
 * @param[in] temp - string containing name of mp3 file
 *
 * @returns nothing
 *
 ******************************************************************************/
void mp3Editor::swap(mp3Editor &mp1, string temp)
{
    mp3Editor mp2;
    ifstream fin;
    if (!fin.is_open())
    fin.open(temp, ios::in | ios::binary);
    if (!fin.is_open())
    {
        cout << "could not open file" << endl;
        return;
    }
    fin >> mp2;
    fin.close();
    ofstream fout;
    fout.open(temp, ios::in | ios::out | ios::binary);
    if (!fout.is_open())
    {
        cout << "changes to " << temp << " were not saved." << endl;
        return;
    }
    fout << mp1;
    mp1 = mp2;
    cout << endl << endl << endl;
    cout << "=============================================================="
            "==================" << endl;
    cout << "NOTE: mp3 files were swapped, but only " <<temp<< " was saved" 
         << endl;
    cout << "=============================================================="
            "==================" << endl;
    fout.close();
}



/**************************************************************************//**
 * @author Bailey Ezra Thorson
 *
 * @par Description:
 *	Finds a null terminator in a c string
 *
 * @param[in]     str - c-style string to search for a null terminator
 * @param[in]     len - length of c-style string passed to the function
 *
 * @returns -1 Function did not find a null terminator
 * @returns n Location of null terminator found by function
 *
 *****************************************************************************/
int mp3Editor::findNullTerminator(char str[], int len)
{
    int i;
    for (i = 0; i < len; i++)
        if (str[i] == '\0')
            return i;
    return -1;
}



/***************************************************************************//**
 * @author Christian Fattig
 *
 * @par Description:
 * This function is used to edit a given field of an mp3 file.  
 * If the inputted field is larger than the requested size, it gets truncated
 * down to the max size allowed. If it is shorter than the max size, the
 * string then gets padded with null terminators up to the max character limit.
 *
 * @param[in,out] tag - holds the current mp3 file in use.
 * @param[in]     size - stores the name of the current mp3 file.
 * @param[in,out] temp - holds what the field gets changed to.
 *
 ******************************************************************************/
void mp3Editor::edit(char tag[], int size, string &temp)
{	
	//checks inputted size and truncates if needed
	if ((int)temp.length() > size)
		temp.resize(size);

	//pads the remainder of the string with "\0"
	while ((int)temp.length() < size)
		temp += '\0';

	//converts the new field into a cstyle string
	//and chops off the "\0" if given
	strncpy(tag, temp.c_str(), size);

	return;
}



/***************************************************************************//**
 * @author Bailey Ezra Thorson
 *
 * @par Description:
 * This function is will set an MP3tag to field defaults. it does not modify
 * fields that the class does not edit (TAG and NULLBYTE) It fills character
 * arrays with null terminators and single characters with a 0
 *
 ******************************************************************************/
void mp3Editor::clear()
{
	int i;
	for (i = 0; i < 30; i++)
		theTags.albumName[i] = '\0';
	for (i = 0; i < 30; i++)
		theTags.artistName[i] = '\0';
	for (i = 0; i < 28; i++)
		theTags.comment[i] = '\0';
	for (i = 0; i < 30; i++)
		theTags.songTitle[i] = '\0';
	for (i = 0; i < 4; i++)
		theTags.year[i] = '\0';
	theTags.track = 0;
	theTags.genre = 0;
}



/***************************************************************************//**
 * @author Jeffrey Ross
 *
 * @par Description:
 * A function that copies the contents from a provided mp3 to another. This
 * function reads in from the file contained in the string temp, and copies
 * them over to mp1.
 * 
 *
 * @param[in] mp1 - mp3 file contents to be copied from contents of string
 * @param[in] temp - string containing name of mp3 file
 *
 * @returns nothing
 *
 ******************************************************************************/
void mp3Editor::copy(mp3Editor &mp1, string temp)
{
    mp3Editor mp2;
    ifstream fin;
    fin.open(temp, ios::in | ios::binary);
    if (!fin.is_open())
    {
        cout << "could not open file" << endl;
        return;
    }
    fin >> mp2;
    mp1 = mp2;
    fin.close();
    cout << endl << endl << endl;
}


