/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef ULTIMA8_GUMPS_CRUAMMOGUMP_H
#define ULTIMA8_GUMPS_CRUAMMOGUMP_H

#include "ultima/ultima8/gumps/cru_stat_gump.h"
#include "ultima/ultima8/misc/p_dynamic_cast.h"

namespace Ultima {
namespace Ultima8 {

class TextWidget;

/**
 * Second box along the bottom of the screen, shows current ammo
 */
class CruAmmoGump : public CruStatGump {
public:
	ENABLE_RUNTIME_CLASSTYPE()

	CruAmmoGump();
	CruAmmoGump(Shape *shape, int x);
	~CruAmmoGump() override;

	// Init the gump, call after construction
	void InitGump(Gump *newparent, bool take_focus = true) override;

	// Paint this Gump
	void PaintThis(RenderSurface *, int32 lerp_factor, bool scaled) override;

	bool loadData(Common::ReadStream *rs, uint32 version);
	void saveData(Common::WriteStream *ws) override;

private:
	Shape *_ammoShape;

	TextWidget *_bulletsText;
	TextWidget *_clipsText;
};

} // End of namespace Ultima8
} // End of namespace Ultima

#endif
