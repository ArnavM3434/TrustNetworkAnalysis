#include "utils.h"
#include <sstream>
#include <fenv.h>
#include <signal.h>
#include <vector>

/**
 * Takes a filename and reads in all the text from the file
 * Newline characters are also just characters in ASCII
 * 
 * @param filename The name of the file that will fill the string
 * @return A string containing the whole text of the given file
 */
std::string file_to_string(const std::string& filename){
std::ifstream text(filename);

std::stringstream strStream;
if (text.is_open()) {
	strStream << text.rdbuf();
}
return strStream.str();
}


/**
* Functions for the removal of whitespace to the left or right of a string (or both)
*
* @param str The string being processed
* @return The processed string
*/
std::string TrimRight(const std::string & str) {
	std::string tmp = str;
	return tmp.erase(tmp.find_last_not_of(" ") + 1);
}


/**
* Functions for the removal of whitespace to the left or right of a string (or both)
*
* @param str The string being processed
* @return The processed string
*/
std::string TrimLeft(const std::string & str) {
	std::string tmp = str;
	return tmp.erase(0, tmp.find_first_not_of(" "));
}


/**
* Functions for the removal of whitespace to the left or right of a string (or both)
*
* @param str The string being processed
* @return The processed string
*/
std::string Trim(const std::string & str) {
	std::string tmp = str;
	return TrimLeft(TrimRight(str));
}


/**
 * Given a string and character, split the string by the character and store in a vector
 * A 'split' string treats the character as a breakpoint and creates a separate item
 * in the output vector for each substring. 
 * 
 * NOTE: The separator character is not included in the substrings.
 * 
 * The total number of substrings created (the length of fields) is returned 
 *  
 * @param str1 The string being split
 * @param sep The separator character
 * @param fields The string vector storing all substrings created by the split
 * @return The number of substrings created
 */
int SplitString(const std::string & str1, char sep, std::vector<std::string> &fields) {
	std::string str = str1;
	std::string::size_type pos;
	
	while((pos=str.find(sep)) != std::string::npos) {
		fields.push_back(str.substr(0,pos));
		str.erase(0,pos+1);  
	}
	fields.push_back(str);
	return fields.size();
}