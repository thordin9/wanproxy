/*
 * Copyright (c) 2011-2012 Juli Mallett. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef	SSH_SSH_KEY_EXCHANGE_H
#define	SSH_SSH_KEY_EXCHANGE_H

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// File:           ssh_key_exchange.h                                         //
// Description:    SSH key check performed on filter session start            //
// Project:        WANProxy XTech                                             //
// Adapted by:     Andreu Vidal Bramfeld-Software                             //
// Last modified:  2015-04-01                                                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

class Buffer;
class Filter;

namespace SSH {
	struct Session;

	class KeyExchange {
	protected:
		const std::string name_;

		KeyExchange(const std::string& xname)
		: name_(xname)
		{ }

	public:
		virtual ~KeyExchange()
		{ }

		std::string name(void) const
		{
			return (name_);
		}

		virtual KeyExchange *clone(void) const = 0;

		virtual bool hash(Buffer *, const Buffer *) const = 0;

		virtual bool input(Filter *, Buffer *) = 0;

		virtual bool init(Buffer *) = 0;

		static void add_algorithms(Session *);
	};
}

#endif /* !SSH_SSH_KEY_EXCHANGE_H */
