#ifndef XML_LIB_H
#define XML_LIB_H

#include <string>
#include <vector>

#ifdef __cplusplus
extern "C" {
#endif
	
int __stdcall LoadXMLFile(const char* XmlFileName, const char* ConfigFileName, unsigned char* pOptr, unsigned char* pOptrseg, unsigned int* pRatValid,
						   unsigned int* pOptionCount);

#ifdef __cplusplus
}
#endif

#endif







