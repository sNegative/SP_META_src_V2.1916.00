#include "stdio.h"
#include "string.h"

#define SYSTEM_LID_MIN_NUM 0
#define SYSTEM_LID_MAX_NUM 11
#define L1_CALIBRATION_LID_MIN_NUM 12
#define L1_CALIBRATION_LID_MAX_NUM 17
#define OTHER_LID_MIN_NUM 18
#define OTHER_LID_MAX_NUM 44
#define LAST_LID_NUM 44
#define STRING_EQUAL 0

extern int Determine_LID_Category(char *LID_Name_para);

typedef enum
{
    RDEB_LID_CATEGORY,//SYSTEM_RELATED_LID_CATEGORY,
    RDCL_LID_CATEGORY,//L1_CALIBRATION_LID_CATEGORY,
    OTHER_LID_CATEGORY
} LID_CATEGORY;


