//=============================================================================
//
// Gl~[Aj[V\¢Ì [Struct_Enemy2_3.h]
//
//=============================================================================

#pragma once

// Aj[Ve[u
struct AnimTable_C_Enemy2_3
{
	int no;		// QuadUV e[uÔ	
	int cnt;		// \¦[v
};

//tuÀW
struct QuadUV_C_Enemy2_3
{
	float u[4];
	float v[4];
};


// UVe[u (\¢ÌQuadUV^Ìzñg_uvTable)
QuadUV_C_Enemy2_3  g_uvTable_Enemy2_3[13] =
{
	//========================================================================================================
	//ºü«
	//========================================================================================================
	//êÚ
	{ 0.0f,  0.1f,	0.0f,	   0.1f ,	         // Ul
	0.27f,	  0.27f,		0.375f,	   0.375f }, // Vl

												 //ñÚ
	{ 0.1f,  0.2f,	0.1f,	   0.2f ,
	0.27f,	  0.27f,		0.375f,	   0.375f },

	//OÚ
	{ 0.2f,  0.3f,	0.2f,	   0.3f ,
	0.27f,	  0.27f,		0.375f,	   0.375f },


	//========================================================================================================
	//ãü«
	//========================================================================================================
	//lÚ
	{ 0.0f,  0.1f,	0.0f,	   0.1f ,	     // Ul
	0.02f,	  0.02f,		0.125f,	   0.125f }, // Vl

												 //ÜÚ
	{ 0.1f,  0.2f,	0.1f,	   0.2f ,
	0.02f,	  0.02f,		0.125f,	   0.125f },

	//ZÚ
	{ 0.2f,  0.3f,	0.2f,	   0.3f ,
	0.02f,	  0.02f,		0.125f,	   0.125f },


	//========================================================================================================
	//¶ü«
	//========================================================================================================
	//µÚ
	{ 0.0f,  0.1f,	0.0f,	   0.1f ,	       // Ul
	0.384f,	  0.384f,		0.5f,	   0.5f }, // Vl

											   //ªÚ
	{ 0.1f,  0.2f,	0.1f,	   0.2f ,
	0.384f,	  0.384f,		0.5f,	   0.5f },

	//ãÚ
	{ 0.2f,  0.3f,	0.2f,	   0.3f ,
	0.384f,	  0.384f,		0.5f,	   0.5f },


	//========================================================================================================
	//Eü«
	//========================================================================================================
	//\Ú
	{ 0.0f,  0.1f,	0.0f,	   0.1f ,	       // Ul
	0.134f,	  0.134f,		0.25f,	  0.25f }, // Vl

											   //\êÚ
	{ 0.1f,  0.2f,	0.1f,	   0.2f ,
	0.134f,	  0.134f,		0.25f,	   0.25f }, // Vl

												//\ñÚ
	{ 0.2f,  0.3f,	0.2f,	   0.3f ,
	0.134f,	  0.134f,		0.25f,	   0.25f },


	//\OÚ(12Æ13Í¯¶)
	{ 0.2f,  0.3f,	0.2f,	   0.3f ,
	0.134f,	  0.134f,		0.25f,	   0.25f }
};


//Aj[Ve[u
AnimTable_C_Enemy2_3 g_anim_Enemy2_3[] =
{
	{ 0,10 },   //êÚ
	{ 1,10 },   //ñÚ
	{ 2,10 },   //OÚ
	{ 3,10 },   //lÚ
	{ 4,10 },   //ÜÚ
	{ 5,10 },   //ZÚ
	{ 6,10 },   //µÚ
	{ 7,10 },   //ªÚ
	{ 8,10 },   //ãÚ
	{ 9,10 },   //\Ú
	{ 10,10 },  //\êÚ
	{ 11,10 },  //\ñÚ
	{ 12,10 },  //\OÚ
	{ 13,10 },  //\lÚ
	{ -1,-1 }
};


// ­Aj[Ve[u
struct AnimTable_Explosion2_3
{
	int no;		// QuadUV e[uÔ	
	int cnt;		// \¦[v
};

//­tuÀW
struct QuadUV_Explosion2_3
{
	float u[4];
	float v[4];
};


// ­UVe[u (\¢ÌQuadUV^Ìzñg_uvTable)
QuadUV_Explosion2_3  g_uvTable_Explosion2_3[17] =
{
	//êÚ
	{ 0.0f,			1.0f / 8.0f,	0.0f,			1.0f / 8.0f ,				// Ul
	0.0f,			0.0f,			1.0f / 4.0f,	1.0f / 4.0f },				// Vl

																				//ñÚ
	{ 1.0f / 8.0f,	2.0f / 8.0f,	1.0f / 8.0f,	2.0f / 8.0f ,
	0.0f,			0.0f,			1.0f / 4.0f,	1.0f / 4.0f },

	//OÚ
	{ 2.0f / 8.0f,	3.0f / 8.0f,	2.0f / 8.0f,	3.0f / 8.0f ,
	0.0f,			0.0f,			1.0f / 4.0f,	1.0f / 4.0f },

	//lÚ
	{ 3.0f / 8.0f,	4.0f / 8.0f,	3.0f / 8.0f,	4.0f / 8.0f ,
	0.0f,			0.0f,			1.0f / 4.0f,	1.0f / 4.0f },

	//ÜÚ
	{ 4.0f / 8.0f,	5.0f / 8.0f,	4.0f / 8.0f,	5.0f / 8.0f ,
	0.0f,	   0.0f,	   1.0f / 4.0f,	    1.0f / 4.0f },

	//ZÚ
	{ 5.0f / 8.0f,	6.0f / 8.0f,	5.0f / 8.0f,	6.0f / 8.0f ,
	0.0f,	0.0f,	1.0f / 4.0f,	1.0f / 4.0f },

	//µÚ
	{ 6.0f / 8.0f,	7.0f / 8.0f,	6.0f / 8.0f,	7.0f / 8.0f ,
	0.0f,	0.0f,	1.0f / 4.0f,	1.0f / 4.0f },

	//ªÚ
	{ 7.0f / 8.0f,	8.0f / 8.0f,	7.0f / 8.0f,	8.0f / 8.0f ,
	0.0f,	0.0f,	1.0f / 4.0f,	1.0f / 4.0f },

	//ãÚ
	{ 0.0f / 8.0f,	1.0f / 8.0f,	0.0f / 8.0f,	1.0f / 8.0f ,
	1.0f / 4.0f,	    1.0f / 4.0f,	2.0f / 4.0f,	2.0f / 4.0f },

	//\Ú
	{ 1.0f / 8.0f,	2.0f / 8.0f,	1.0f / 8.0f,	2.0f / 8.0f ,
	1.0f / 4.0f,  1.0f / 4.0f,	2.0f / 4.0f,	2.0f / 4.0f },

	//\êÚ
	{ 2.0f / 8.0f,	3.0f / 8.0f,	2.0f / 8.0f,	3.0f / 8.0f ,
	1.0f / 4.0f,  1.0f / 4.0f,	2.0f / 4.0f,	2.0f / 4.0f },

	//\ñÚ
	{ 3.0f / 8.0f,	4.0f / 8.0f,	3.0f / 8.0f,	4.0f / 8.0f ,
	1.0f / 4.0f,	1.0f / 4.0f,	2.0f / 4.0f,	2.0f / 4.0f },

	//\OÚ
	{ 4.0f / 8.0f,	5.0f / 8.0f,	4.0f / 8.0f,	5.0f / 8.0f ,
	1.0f / 4.0f,	    1.0f / 4.0f,	2.0f / 4.0f,	2.0f / 4.0f },

	//\lÚ
	{ 5.0f / 8.0f,	6.0f / 8.0f,	5.0f / 8.0f,	6.0f / 8.0f ,
	1.0f / 4.0f,      1.0f / 4.0f,	2.0f / 4.0f,	2.0f / 4.0f },

	//\ÜÚ
	{ 6.0f / 8.0f,	7.0f / 8.0f,	6.0f / 8.0f,	7.0f / 8.0f ,
	1.0f / 4.0f,      1.0f / 4.0f,	2.0f / 4.0f,	2.0f / 4.0f },

	//\ZÚ(16Æ17Í¯¶)
	{ 7.0f / 8.0f,	8.0f / 8.0f,	7.0f / 8.0f,	8.0f / 8.0f ,
	1.0f / 4.0f,	    1.0f / 4.0f,	2.0f / 4.0f,	2.0f / 4.0f },
	//\µÚ
	{ 7.0f / 8.0f,	8.0f / 8.0f,	7.0f / 8.0f,	8.0f / 8.0f ,
	1.0f / 4.0f,	    1.0f / 4.0f,	2.0f / 4.0f,	2.0f / 4.0f }
};


//­Aj[Ve[u
AnimTable_Explosion2_3 g_anim_Explosion2_3[] =
{
	{ 0,10 },   //êÚ
	{ 1,10 },   //ñÚ
	{ 2,10 },   //OÚ
	{ 3,10 },   //lÚ
	{ 4,10 },   //ÜÚ
	{ 5,10 },   //ZÚ
	{ 6,10 },   //µÚ
	{ 7,10 },   //ªÚ
	{ 8,10 },   //ãÚ
	{ 9,10 },   //\Ú
	{ 10,10 },  //\êÚ
	{ 11,10 },  //\ñÚ
	{ 12,10 },  //\OÚ
	{ 13,10 },  //\lÚ
	{ 14,10 },  //\ÜÚ
	{ 15,10 },  //\ZÚ
	{ 16,10 },  //\ZÚ
	{ -1,-1 }
};