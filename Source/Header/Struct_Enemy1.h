//=============================================================================
//
// エネミーアニメーション構造体 [Struct_Enemy1.h]
//
//=============================================================================

#pragma once

// アニメーションテーブル
struct AnimTable_C_Enemy1
{
	int no;		// QuadUV テーブル番号	
	int cnt;		// 表示ループ数
};

//ＵＶ座標
struct QuadUV_C_Enemy1
{
	float u[4];
	float v[4];
};


// UVテーブル (構造体QuadUV型の配列g_uvTable)
QuadUV_C_Enemy1  g_uvTable_Enemy1[13] =
{
	//========================================================================================================
	//下向き
	//========================================================================================================
	//一枚目
	{ 0.3f,  0.4f,	0.3f,	   0.4f ,	         // U値
	0.27f,	  0.27f,		0.375f,	   0.375f }, // V値

	//二枚目
	{ 0.4f,  0.5f,	0.4f,	   0.5f ,
	0.27f,	  0.27f,		0.375f,	   0.375f },

	//三枚目
	{ 0.5f,  0.6f,	0.5f,	   0.6f ,
	0.27f,	  0.27f,		0.375f,	   0.375f },


	//========================================================================================================
	//上向き
	//========================================================================================================
	//四枚目
	{ 0.3f,  0.4f,	0.3f,	   0.4f ,	     // U値
	0.02f,	  0.02f,		0.125f,	   0.125f }, // V値

	//五枚目
	{ 0.4f,  0.5f,	0.4f,	   0.5f ,
	0.02f,	  0.02f,		0.125f,	   0.125f }, 

	//六枚目
	{ 0.5f,  0.6f,	0.5f,	   0.6f ,
	0.02f,	  0.02f,		0.125f,	   0.125f }, 


	//========================================================================================================
	//左向き
	//========================================================================================================
	//七枚目
	{ 0.3f,  0.4f,	0.3f,	   0.4f ,	       // U値
	0.384f,	  0.384f,		0.5f,	   0.5f }, // V値

	//八枚目
	{ 0.4f,  0.5f,	0.4f,	   0.5f ,
	0.384f,	  0.384f,		0.5f,	   0.5f }, 

	//九枚目
	{ 0.5f,  0.6f,	0.5f,	   0.6f ,
	0.384f,	  0.384f,		0.5f,	   0.5f }, 


	//========================================================================================================
	//右向き
	//========================================================================================================
	//十枚目
	{ 0.3f,  0.4f,	0.3f,	   0.4f ,	       // U値
	0.134f,	  0.134f,		0.25f,	  0.25f }, // V値

	//十一枚目
	{ 0.4f,  0.5f,	0.4f,	   0.5f ,
	0.134f,	  0.134f,		0.25f,	   0.25f }, // V値

	//十二枚目
	{ 0.5f,  0.6f,	0.5f,	   0.6f ,
	0.134f,	  0.134f,		0.25f,	   0.25f },


	//十三目(12と13は同じ)
	{ 0.5f,  0.6f,	0.5f,	   0.6f ,
	0.134f,	  0.134f,		0.25f,	   0.25f } 

};


QuadUV_C_Enemy1  g_uvTable_Enemy2[13] =
{
	//========================================================================================================
	//下向き
	//========================================================================================================
	//一枚目
	{ 0.6f,  0.7f,	0.6f,	   0.7f ,	         // U値
	0.27f,	  0.27f,		0.375f,	   0.375f }, // V値

												 //二枚目
	{ 0.7f,  0.8f,	0.7f,	   0.8f ,
	0.27f,	  0.27f,		0.375f,	   0.375f },

	//三枚目
	{ 0.8f,  0.9f,	0.8f,	   0.9f ,
	0.27f,	  0.27f,		0.375f,	   0.375f },


	//========================================================================================================
	//上向き
	//========================================================================================================
	//四枚目
	{ 0.6f,  0.7f,	0.6f,	   0.7f ,	     // U値
	0.02f,	  0.02f,		0.125f,	   0.125f }, // V値

												 //五枚目
	{ 0.7f,  0.8f,	0.7f,	   0.8f ,
	0.02f,	  0.02f,		0.125f,	   0.125f },

	//六枚目
	{ 0.8f,  0.9f,	0.8f,	   0.9f ,
	0.02f,	  0.02f,		0.125f,	   0.125f },


	//========================================================================================================
	//左向き
	//========================================================================================================
	//七枚目
	{ 0.6f,  0.7f,	0.6f,	   0.7f ,	       // U値
	0.384f,	  0.384f,		0.5f,	   0.5f }, // V値

											   //八枚目
	{ 0.7f,  0.8f,	0.7f,	   0.8f ,
	0.384f,	  0.384f,		0.5f,	   0.5f },

	//九枚目
	{ 0.8f,  0.9f,	0.8f,	   0.9f ,
	0.384f,	  0.384f,		0.5f,	   0.5f },


	//========================================================================================================
	//右向き
	//========================================================================================================
	//十枚目
	{ 0.6f,  0.7f,	0.6f,	   0.7f ,	       // U値
	0.134f,	  0.134f,		0.25f,	  0.25f }, // V値

											   //十一枚目
	{ 0.7f,  0.8f,	0.7f,	   0.8f ,
	0.134f,	  0.134f,		0.25f,	   0.25f }, // V値

												//十二枚目
	{ 0.8f,  0.9f,	0.8f,	   0.9f ,
	0.134f,	  0.134f,		0.25f,	   0.25f },


	//十三目(12と13は同じ)
	{ 0.8f,  0.9f,	0.8f,	   0.9f ,
	0.134f,	  0.134f,		0.25f,	   0.25f }

};


QuadUV_C_Enemy1  g_uvTable_Enemy3[13] =
{
	//========================================================================================================
	//下向き
	//========================================================================================================
	//一枚目
	{ 0.0f,  0.1f,	0.0f,	   0.1f ,	         // U値
	0.27f,	  0.27f,		0.375f,	   0.375f }, // V値

												 //二枚目
	{ 0.1f,  0.2f,	0.1f,	   0.2f ,
	0.27f,	  0.27f,		0.375f,	   0.375f },

	//三枚目
	{ 0.2f,  0.3f,	0.2f,	   0.3f ,
	0.27f,	  0.27f,		0.375f,	   0.375f },


	//========================================================================================================
	//上向き
	//========================================================================================================
	//四枚目
	{ 0.0f,  0.1f,	0.0f,	   0.1f ,	     // U値
	0.02f,	  0.02f,		0.125f,	   0.125f }, // V値

												 //五枚目
	{ 0.1f,  0.2f,	0.1f,	   0.2f ,
	0.02f,	  0.02f,		0.125f,	   0.125f },

	//六枚目
	{ 0.2f,  0.3f,	0.2f,	   0.3f ,
	0.02f,	  0.02f,		0.125f,	   0.125f },


	//========================================================================================================
	//左向き
	//========================================================================================================
	//七枚目
	{ 0.0f,  0.1f,	0.0f,	   0.1f ,	       // U値
	0.384f,	  0.384f,		0.5f,	   0.5f }, // V値

											   //八枚目
	{ 0.1f,  0.2f,	0.1f,	   0.2f ,
	0.384f,	  0.384f,		0.5f,	   0.5f },

	//九枚目
	{ 0.2f,  0.3f,	0.2f,	   0.3f ,
	0.384f,	  0.384f,		0.5f,	   0.5f },


	//========================================================================================================
	//右向き
	//========================================================================================================
	//十枚目
	{ 0.0f,  0.1f,	0.0f,	   0.1f ,	       // U値
	0.134f,	  0.134f,		0.25f,	  0.25f }, // V値

											   //十一枚目
	{ 0.1f,  0.2f,	0.1f,	   0.2f ,
	0.134f,	  0.134f,		0.25f,	   0.25f }, // V値

												//十二枚目
	{ 0.2f,  0.3f,	0.2f,	   0.3f ,
	0.134f,	  0.134f,		0.25f,	   0.25f },


	//十三目(12と13は同じ)
	{ 0.2f,  0.3f,	0.2f,	   0.3f ,
	0.134f,	  0.134f,		0.25f,	   0.25f }

};


//アニメーションテーブル
AnimTable_C_Enemy1 g_anim_Enemy1[] =
{
	{ 0,10 },   //一枚目
	{ 1,10 },   //二枚目
	{ 2,10 },   //三枚目
	{ 3,10 },   //四枚目
	{ 4,10 },   //五枚目
	{ 5,10 },   //六枚目
	{ 6,10 },   //七枚目
	{ 7,10 },   //八枚目
	{ 8,10 },   //九枚目
	{ 9,10 },   //十枚目
	{ 10,10 },  //十一枚目
	{ 11,10 },  //十二枚目
	{ 12,10 },  //十三枚目
	{ 13,10 },  //十四枚目
	{ -1,-1 }
};


// 爆発アニメーションテーブル
struct AnimTable_Explosion1
{
	int no;		// QuadUV テーブル番号	
	int cnt;		// 表示ループ数
};

//爆発ＵＶ座標
struct QuadUV_Explosion1
{
	float u[4];
	float v[4];
};

// 爆発UVテーブル (構造体QuadUV型の配列g_uvTable)
QuadUV_Explosion1  g_uvTable_Explosion[17] =
{
	//一枚目
	{ 0.0f,			1.0f / 8.0f,	0.0f,			1.0f / 8.0f ,				// U値
	0.0f,			0.0f,			1.0f / 4.0f,	1.0f / 4.0f },				// V値

																				//二枚目
	{ 1.0f / 8.0f,	2.0f / 8.0f,	1.0f / 8.0f,	2.0f / 8.0f ,
	0.0f,			0.0f,			1.0f / 4.0f,	1.0f / 4.0f },

	//三枚目
	{ 2.0f / 8.0f,	3.0f / 8.0f,	2.0f / 8.0f,	3.0f / 8.0f ,
	0.0f,			0.0f,			1.0f / 4.0f,	1.0f / 4.0f },

	//四枚目
	{ 3.0f / 8.0f,	4.0f / 8.0f,	3.0f / 8.0f,	4.0f / 8.0f ,
	0.0f,			0.0f,			1.0f / 4.0f,	1.0f / 4.0f },

	//五枚目
	{ 4.0f / 8.0f,	5.0f / 8.0f,	4.0f / 8.0f,	5.0f / 8.0f ,
	0.0f,	   0.0f,	   1.0f / 4.0f,	    1.0f / 4.0f },

	//六枚目
	{ 5.0f / 8.0f,	6.0f / 8.0f,	5.0f / 8.0f,	6.0f / 8.0f ,
	0.0f,	0.0f,	1.0f / 4.0f,	1.0f / 4.0f },

	//七枚目
	{ 6.0f / 8.0f,	7.0f / 8.0f,	6.0f / 8.0f,	7.0f / 8.0f ,
	0.0f,	0.0f,	1.0f / 4.0f,	1.0f / 4.0f },

	//八枚目
	{ 7.0f / 8.0f,	8.0f / 8.0f,	7.0f / 8.0f,	8.0f / 8.0f ,
	0.0f,	0.0f,	1.0f / 4.0f,	1.0f / 4.0f },

	//九枚目
	{ 0.0f / 8.0f,	1.0f / 8.0f,	0.0f / 8.0f,	1.0f / 8.0f ,
	1.0f / 4.0f,	    1.0f / 4.0f,	2.0f / 4.0f,	2.0f / 4.0f },

	//十枚目
	{ 1.0f / 8.0f,	2.0f / 8.0f,	1.0f / 8.0f,	2.0f / 8.0f ,
	1.0f / 4.0f,  1.0f / 4.0f,	2.0f / 4.0f,	2.0f / 4.0f },

	//十一枚目
	{ 2.0f / 8.0f,	3.0f / 8.0f,	2.0f / 8.0f,	3.0f / 8.0f ,
	1.0f / 4.0f,  1.0f / 4.0f,	2.0f / 4.0f,	2.0f / 4.0f },

	//十二枚目
	{ 3.0f / 8.0f,	4.0f / 8.0f,	3.0f / 8.0f,	4.0f / 8.0f ,
	1.0f / 4.0f,	1.0f / 4.0f,	2.0f / 4.0f,	2.0f / 4.0f },

	//十三枚目
	{ 4.0f / 8.0f,	5.0f / 8.0f,	4.0f / 8.0f,	5.0f / 8.0f ,
	1.0f / 4.0f,	    1.0f / 4.0f,	2.0f / 4.0f,	2.0f / 4.0f },

	//十四目
	{ 5.0f / 8.0f,	6.0f / 8.0f,	5.0f / 8.0f,	6.0f / 8.0f ,
	1.0f / 4.0f,      1.0f / 4.0f,	2.0f / 4.0f,	2.0f / 4.0f },

	//十五枚目
	{ 6.0f / 8.0f,	7.0f / 8.0f,	6.0f / 8.0f,	7.0f / 8.0f ,
	1.0f / 4.0f,      1.0f / 4.0f,	2.0f / 4.0f,	2.0f / 4.0f },

	//十六枚目(16と17は同じ)
	{ 7.0f / 8.0f,	8.0f / 8.0f,	7.0f / 8.0f,	8.0f / 8.0f ,
	1.0f / 4.0f,	    1.0f / 4.0f,	2.0f / 4.0f,	2.0f / 4.0f },
	//十七枚目
	{ 7.0f / 8.0f,	8.0f / 8.0f,	7.0f / 8.0f,	8.0f / 8.0f ,
	1.0f / 4.0f,	    1.0f / 4.0f,	2.0f / 4.0f,	2.0f / 4.0f }
};

//爆発アニメーションテーブル
AnimTable_Explosion1 g_anim_Explosion1[] =
{
	{ 0,10 },   //一枚目
	{ 1,10 },   //二枚目
	{ 2,10 },   //三枚目
	{ 3,10 },   //四枚目
	{ 4,10 },   //五枚目
	{ 5,10 },   //六枚目
	{ 6,10 },   //七枚目
	{ 7,10 },   //八枚目
	{ 8,10 },   //九枚目
	{ 9,10 },   //十枚目
	{ 10,10 },  //十一枚目
	{ 11,10 },  //十二枚目
	{ 12,10 },  //十三枚目
	{ 13,10 },  //十四枚目
	{ 14,10 },  //十五枚目
	{ 15,10 },  //十六枚目
	{ 16,10 },  //十六枚目
	{ -1,-1 }
};