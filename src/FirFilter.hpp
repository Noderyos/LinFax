// hamfax -- an application for sending and receiving amateur radio facsimiles
// Copyright (C) 2002
// Christof Schmitt, DH1CS <cschmitt@users.sourceforge.net>
//  
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//  
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#ifndef FIRFILTER_HPP
#define FIRFILTER_HPP

#include <valarray>

/**
 * This template class implements a FIR filter (finite impulse response). 
 * The template parameter defines the type of input and output data.
 */

template <class T> class FirFilter {
public:
	/**
	 * Create the FirFilter.
	 * \param n is the size of buffer and coefficient array
	 */
	FirFilter(const size_t n);

	/**
	 * Set new coefficients.
	 * \param c are the new coefficients; the size has to be the same 
	 * as the size of the filter!
	 */
	void setCoeffs(const std::valarray<T>& c);

	/**
	 * Set new buffer content, e.g. all zero.
	 * \param b is the new buffer content;, the size has to be the same
	 * as the old!
	 */
	void setBuffer(const std::valarray<T>& b);

	/**
	 * Return the size of the filter buffer.
	 */
	size_t size() const;

        /**
	 * Pass one sample through the filter and get the result as return value.
	 */
	T filterSample(const T& sample);

	/**
	 * Get current buffer; useful for debugging purposes.
	 */
	std::valarray<T> getBuffer() const;
private:
        std::valarray<T> coeffs;
        std::valarray<T> buffer;
        T* current;
};

template <class T> FirFilter<T>::FirFilter(size_t n)
	: coeffs(n), buffer(n)
{
	current=&buffer[0];
}

template <class T> void FirFilter<T>::setCoeffs(const std::valarray<T>& c)
{
	coeffs=c;
}

template <class T> inline void FirFilter<T>::setBuffer(const std::valarray<T>& b)
{
	buffer=b;
}

template <class T> inline size_t FirFilter<T>::size() const
{
	return buffer.size();
}

template <class T> inline T FirFilter<T>::filterSample(const T& sample)
{
        const T* c=&coeffs[0];
	T* const c_end=&coeffs[coeffs.size()];
	T* const b_begin=&buffer[0];
	T* const b_end=&buffer[buffer.size()];
        T sum=0;

        // replace oldest value with current
        *current=sample;

	// convolution
	while(current!=b_end)
		sum+=(*current++)*(*c++);
	current=b_begin;
	while(c!=c_end)
		sum+=(*current++)*(*c++);

        // point again to oldest value
        if(--current<b_begin)
                current=b_end-1;

        return sum;
}

template <class T>
inline std::valarray<T> FirFilter<T>::getBuffer(void) const
{
	return buffer;
}
#endif
