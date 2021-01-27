﻿/*!	@file
	@brief ズーム倍率算出
*/
/*
	This software is provided 'as-is', without any express or implied
	warranty. In no event will the authors be held liable for any damages
	arising from the use of this software.

	Permission is granted to anyone to use this software for any purpose,
	including commercial applications, and to alter it and redistribute it
	freely, subject to the following restrictions:

		1. The origin of this software must not be misrepresented;
		   you must not claim that you wrote the original software.
		   If you use this software in a product, an acknowledgment
		   in the product documentation would be appreciated but is
		   not required.

		2. Altered source versions must be plainly marked as such,
		   and must not be misrepresented as being the original software.

		3. This notice may not be removed or altered from any source
		   distribution.
*/

#ifndef SAKURA_ZOOM_0CD4E589_F708_48BF_8601_8BF851827765_H_
#define SAKURA_ZOOM_0CD4E589_F708_48BF_8601_8BF851827765_H_
#pragma once

#include <vector>

/*!
	@brief ズーム設定を保持
*/
struct ZoomSetting
{
	/*!
		@brief コンストラクタ
		@param[in] nZoomFactors	ズーム倍率の並び(昇順)
		@param[in] nValueMin	下限値(上限値以下)
		@param[in] nValueMax	上限値(下限値以上)
		@param[in] nValueUnit	値の最小単位(0以上)
	*/
	template<size_t nCount>
	ZoomSetting( const double (&nZoomFactors)[nCount], double nValueMin, double nValueMax, double nValueUnit ) :
		m_vZoomFactors( std::begin( nZoomFactors ), std::end( nZoomFactors ) ),
		m_nValueMin( nValueMin ),
		m_nValueMax( nValueMax ),
		m_nValueUnit( nValueUnit )
	{}

	const std::vector<double> m_vZoomFactors;
	const double m_nValueMin;
	const double m_nValueMax;
	const double m_nValueUnit;

	bool IsValid() const;
};

bool GetZoomedValue( const ZoomSetting& zoomSetting, double nBaseValue, double nCurrentZoom, int nSteps, double* pnValueOut, double* pnZoomOut );
#endif /* SAKURA_ZOOM_0CD4E589_F708_48BF_8601_8BF851827765_H_ */
