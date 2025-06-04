typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

#ifdef __cplusplus
extern "C" {
#endif

    int __stdcall mt6620_FMTxRfLevel(uint8_t level, uint16_t *addr_3C, uint16_t *addr_3D);
    int __stdcall mt6620_FMTxAudioDeviation(uint32_t deviation,
                                            uint16_t *addr_AB, uint16_t *addr_AC,
                                            uint16_t *addr_AD, uint16_t *addr_AE,
                                            uint16_t *addr_AF, uint16_t *addr_F4,
                                            uint16_t *addr_F5, uint16_t *addr_B1);
    int __stdcall mt6620_FMTxPilotDeviation(uint32_t deviation,
                                            uint16_t *addr_AB, uint16_t *addr_AC,
                                            uint16_t *addr_AD, uint16_t *addr_AE,
                                            uint16_t *addr_AF, uint16_t *addr_F4,
                                            uint16_t *addr_F5, uint16_t *addr_B1);
    int __stdcall mt6620_FMTxRDSDeviation(uint16_t deviation,
                                          uint16_t *addr_AB, uint16_t *addr_AC,
                                          uint16_t *addr_AD, uint16_t *addr_AE,
                                          uint16_t *addr_AF, uint16_t *addr_F4,
                                          uint16_t *addr_F5, uint16_t *addr_B1);
    int __stdcall mt6620_FMTxStereo(uint8_t stereo,
                                    uint16_t *addr_AB, uint16_t *addr_AC,
                                    uint16_t *addr_AD, uint16_t *addr_AE,
                                    uint16_t *addr_AF, uint16_t *addr_F4,
                                    uint16_t *addr_F5, uint16_t *addr_B1);

#ifdef __cplusplus
}
#endif

