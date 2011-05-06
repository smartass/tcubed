/*
 * Copyright (c) 2011 The TCubed Team <jpl@codethink.co.uk>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include "engine.hpp"

uint8_t Engine::cube[3][3][3] = { { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} }
                                , { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} }
                                , { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} }
};

uint8_t Engine::getOwner( uint8_t x
                        , uint8_t y
                        , uint8_t z
) {
	return Engine::cube[x][y][z];
}

void Engine::setOwner( uint8_t x
                     , uint8_t y
                     , uint8_t z
                     , uint8_t owner
) {
	Engine::cube[x][y][z] = owner;
}

void Engine::rotateSide( uint8_t x
                       , uint8_t y
                       , uint8_t z
                       , uint8_t direction = 0
)
{
	// TODO
}

// This functions searches for victory through a just changed point (x, y, z).
uint8_t Engine::checkForVictory( uint8_t x
                               , uint8_t y
                               , uint8_t z
)
{
	// First, check parallelly to the axes:
	if ( (cube[0][y][z] & cube[1][y][z] & cube[2][y][z])
	  || (cube[x][0][z] & cube[x][1][z] & cube[x][2][z])
	  || (cube[x][y][0] & cube[x][y][1] & cube[x][y][2])
	) {
		return cube[x][y][z];
	}

	// Now check diagonally:
	if (cube[x][y][z] != cube[1][1][1]) {
		return 0;
	} else if (cube[x][y][z] == cube[2-x][2-y][2-z]) {
		return cube[x][y][z];
	} else {
		return 0;
	}
}
