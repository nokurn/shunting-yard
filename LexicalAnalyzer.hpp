// Copyright (c) Jeremiah Z. Griffin <nokurn@gmail.com>
//
// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
// ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
// ACTION OF CONTRACT, NEGLIGENCE NEGLIGENCE OR OTHER TORTIOUS ACTION,
// ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
// SOFTWARE.

#ifndef hpp_ShuntingYard_LexicalAnalyzer
#define hpp_ShuntingYard_LexicalAnalyzer

#include "Token.hpp"
#include <iosfwd>
#include <optional>

class LexicalAnalyzer
{
public:
    explicit LexicalAnalyzer(std::istream& is);

    std::optional<Token> get();

    template<typename OutputIt>
    OutputIt get(OutputIt first)
    {
        while (auto t = get()) {
            *first++ = *t;
        }

        return first;
    }

private:
    std::istream& _is;

    std::optional<Token> getWhitespace();
    std::optional<Token> getNumericConstant();
    std::optional<Token> getPunctuation();
};

#endif // hpp_ShuntingYard_LexicalAnalyzer
