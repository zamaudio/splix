/*
 * 	band.h			(C) 2006, Aurélien Croc (AP²C)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; version 2 of the License.
 * 
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the
 *  Free Software Foundation, Inc.,
 *  59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 *  $Id$
 * 
 */
#ifndef BAND_H_
#define BAND_H_


class Band
{
	protected:
		unsigned char*	_band;
		unsigned long	_width;
		unsigned long	_height;
		unsigned long	_line;
		unsigned long	_clipping;
		
	protected:
		unsigned char*	_algorithm0(unsigned long *size);
		unsigned char*	_algorithm11(unsigned long *size);

	public:
		Band(unsigned long bandWidth, unsigned long bandHeight);
		~Band();

	public:
		unsigned long	width() const {return _width * 8;}
		unsigned long	height() const {return _height;}
		unsigned long	line() const {return _line;}
		unsigned long	clipping() const {return _clipping * 8;}

		void		setLine(unsigned long line) {_line = line;}
		void		setClipping(unsigned long c) 
				{_clipping = (c + 7) / 8;}



		void		clean() {_line = 0;}
		int		addLine(unsigned char *line, unsigned long width);

		unsigned char*	exportBand(int algorithm, unsigned long *size);

		bool		isFull() const 
				{return _line == _height ? true : false;}
};

#endif /* BAND_H_ */
