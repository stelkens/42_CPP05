# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    classSkript.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tstelken <tstelken@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/20 16:49:21 by tstelken          #+#    #+#              #
#    Updated: 2026/10/07 11:19:53 by tstelken         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: ./classSkript.sh ClassName"
    exit 1
fi

CLASS=$1
UPPER=$(echo "$CLASS" | tr '[:lower:]' '[:upper:]')

mkdir -p src
mkdir -p include

########################################
# Header
########################################

cat > "include/${CLASS}.hpp" << EOF
#ifndef ${UPPER}_HPP
#define ${UPPER}_HPP

class $CLASS
{
	private:

	public:
		$CLASS();
		$CLASS(const $CLASS &other);
		~$CLASS();

		$CLASS &operator=(const $CLASS &other);

};

#endif
EOF

########################################
# Source
########################################

cat > "src/${CLASS}.cpp" << EOF
#include "${CLASS}.hpp"

$CLASS::$CLASS(){
}

$CLASS::$CLASS(const $CLASS &other){
	*this = other;
}

$CLASS::~$CLASS(){
}

$CLASS &$CLASS::operator=(const $CLASS &other){
	if (this != &other)
	{
	}
	return *this;
}
EOF

########################################
# Update Makefile
########################################

# SRC
if ! grep -q "${CLASS}.cpp" Makefile; then
    sed -i "/utils.cpp\\\\/a\\
\t\t\t\t\t\t${CLASS}.cpp\\\\
" Makefile
fi

# HEADERS
if ! grep -q "${CLASS}.hpp" Makefile; then
    sed -i "/utils.hpp/a\\
\t\t\t\t\t\t\t${CLASS}.hpp \\\\
" Makefile
fi

echo "Created:"
echo "  include/${CLASS}.hpp"
echo "  src/${CLASS}.cpp"
echo "Updated Makefile."