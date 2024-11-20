/***************************************************************************//**
 *@file
 *
 *@brief The header function containing the mp3Editor class
 ******************************************************************************/
#pragma pack(1)
#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<fstream>
#include<string>

using namespace std; 

#ifndef __MP3EDITOR__H_ 
#define __MP3EDITOR__H_
/*!
* @brief allows access to mp3Editor through functions and contains a structure
* to hold information regarding the mp3 files.
*/
class mp3Editor
{ 
public:       
    mp3Editor();        
    ~mp3Editor();
    mp3Editor(mp3Editor &mp3E);
    void setSongTitle(string &s); 
    void setArtistName(string &s);
    void setAlbumName(string &s);
    void setComment(string &s);
    void setYear(string &year);
    void setTrack(char &track);
    void setGenre(char &genre);
    string getSongTitle(); 
    string getArtistName();
    string getAlbumName();
    string getComment();
    string getYear();
    char getTrack();
    char getGenre();
    bool operator==(mp3Editor &mp3E); 
    bool operator!=(mp3Editor &mp3E); 
    bool operator=(mp3Editor &mp3E); 
    friend ofstream &operator<<(ofstream &out, mp3Editor &mp3E);
    friend ifstream &operator>>(ifstream &out, mp3Editor &mp3E); 
    friend ostream &operator<<(ostream &out, mp3Editor &mp3E);
    void swap(mp3Editor &mp1, string string);
    void copy(mp3Editor &mp1, string temp);
    void clear();
private: 
    /*!
    * @brief holds the information for the last 128 bits of the mp3 file
    */
    struct mp3Tag
    { 
        char TAG[3];          /*!< contains "TAG" */
        char songTitle[30];   /*!< contains the title of the track */
        char artistName[30];  /*!< contains the name of the artist */
        char albumName[30];   /*!< contains the title of the album */
        char year[4];         /*!< contains the year of production */
        char comment[28];     /*!< contains a comment */
        char NULLBYTE;        /*!< zero byte */
        unsigned char track;  /*!< contains the track number on the album */
        unsigned char genre;  /*!< contains the number of the genre */
    }; // you may not add any other data without approval
    int findNullTerminator(char str[], int len);
    void edit(char tag[], int size, string &temp);
    mp3Tag theTags; /*!< A structure containing the information */
};
#endif

