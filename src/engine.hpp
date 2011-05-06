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

#pragma once
#ifndef TCUBED_ENGINE_HPP_GUARD
#define TCUBED_ENGINE_HPP_GUARD

#include <cstdint> // uint8_t

/*
 * TODO: reconsider using a singleton.
 */

class Engine
{
	public:
		static uint8_t getOwner( uint8_t x
		                       , uint8_t y
		                       , uint8_t z
		);

		static void setOwner( uint8_t x
		                    , uint8_t y
		                    , uint8_t z
		                    , uint8_t owner
		);

		static void rotateSide( uint8_t x         // x coordinate of the pivot point
		                      , uint8_t y         // y coordinate of the pivot point
		                      , uint8_t z         // z coordinate of the pivot point
		                      , uint8_t direction // TODO: define direction
		);

		static uint8_t checkForVictory( uint8_t x
		                              , uint8_t y
		                              , uint8_t z
		);

	private:
		// prevent initialization:
		Engine();
		Engine(const Engine&);
		// Engine& operator=(const Engine&);

		static uint8_t cube[3][3][3];
};

#endif // TCUBED_ENGINE_HPP_GUARD
