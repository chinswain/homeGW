/*
  Written by Diogo Gomes, diogogomes@gmail.com

  Copyright (c) 2014 Diogo Gomes.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

*/

#ifndef HomeGW_h
#define HomeGW_h

#if ARDUINO < 100
  #include <WProgram.h>
#else
  #include <Arduino.h>
#endif

#include <plugin.h>


class HomeGW {

	private:
		uint8_t pin;

		static uint8_t MAX_PLUGINS; 

		static void handleInterrupt();

	public:
		static Plugin **plugin;
		HomeGW(uint8_t max_plugins);
		~HomeGW();
	
		bool setup(uint8_t pin);
		void tick();
		void registerPlugin(Plugin *);
};

#endif
