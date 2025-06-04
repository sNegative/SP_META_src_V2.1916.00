#ifndef META_NVRAM_cb_h
#define META_NVRAM_cb_h
#include "wmmeta.h"


void __stdcall NVRAM_node_read_rec_cnf_cb( const FT_NVRAM_READ_CNF *cnf, const short token, void *usrData);
void __stdcall NVRAM_node_write_rec_cnf_cb( const FT_NVRAM_WRITE_CNF *cnf, const short token, void *usrData);

#endif