#!/bin/bash
echoCmd() {
	echo -e "\033[31;46m"$1"\033[0m"
}
WORK_DIR="$( dirname "$0"  )"
cd $WORK_DIR
WORK_DIR=`pwd`
OS=`uname`

cleos create key

cleos wallet create -n vot
#Private key: 5K2mzpWm7N6RRYEndfV1LgMKXo51oNHT8GfWHWYCVAxT3tVjthg
#Public key: EOS7Atb9bLnsUXdHmC9HVS8NaF6i1wwY13grCBnX3pmxz4rMNjziM

#Private key: 5KQnniY4P6T3PuYAGcvrBR3BBPgd1vNRATMuNPxvgVKSQMcpMZw
#Public key: EOS7tcXZthMFBJ51PjFt2ag7fU65buvCiNQWSACxpoft5cFQc6DeK

KEY_PRIVATE_11= 5K2mzpWm7N6RRYEndfV1LgMKXo51oNHT8GfWHWYCVAxT3tVjthg
KEY_PUB_11= 5K2mzpWm7N6RRYEndfV1LgMKXo51oNHT8GfWHWYCVAxT3tVjthg

KEY_PRIVATE_2= 5KQnniY4P6T3PuYAGcvrBR3BBPgd1vNRATMuNPxvgVKSQMcpMZw
KEY_PUB_2= EOS7tcXZthMFBJ51PjFt2ag7fU65buvCiNQWSACxpoft5cFQc6DeK

KEY_PRIVATE_1=5KZG619Fht23AYGuh3Py8ZapQkrEWrRy3A7bax5eegoCWYfnvTv
KEY_PUB_1=EOS8F9J5oceGUHzJRU63jTxaJ7j4chPEcBLjpAaFpMfqpbLUKKeMM

KEY_PRIVATE_4=5JnX3aENCraodCwALemQR488XnvtYKF3Yjr8UPPuSdqVnJ7Y4j6
KEY_PUB_4=EOS6B3YWEnEk2cNJekvr2cCC8C572F9ZUBkQCU1uK4x6sBmzo95KN


#PW5JfnU5vDtADBV8Ac4zDQCdL5n9HxngTKzMPCP4hXyXNNS3iUoz2
#build code
cd $WORK_DIR/ballot
#eosiocpp -o ballot.wast ballot.cpp
#eosiocpp -g ballot.abi ballot.cpp
cd -


if [ ! -f $WORK_DIR"/../passwd.txt" ];then
	../setup.sh
fi
cat $WORK_DIR/../passwd.txt | cleos wallet unlock -n vot
cleos wallet import -n vot $KEY_PRIVATE_1
cleos wallet import -n vot $KEY_PRIVATE_2

#kill old nodeos
if [ $OS"x" == "Darwinx" ];then
	ps a > ./tmp.txt
	grep "nodeos" ./tmp.txt|awk '{print $1}'|xargs kill -9
	rm ./tmp.txt
else
	ps auxf|grep "nodeos -e"|awk '{print $2}'|xargs kill -9
fi
#launch nodeos --resync  –replay-blockchain --hard-replay-blockchain
echo "launch nodeos ......"
nohup nodeos -e -p eosio --contracts-console --plugin eosio::chain_api_plugin --plugin eosio::history_api_plugin --plugin eosio::http_plugin   --data-dir ./.tmpdata/eosio 2>&1 1>nodeos.log &
sleep 2


cleos create account eosio acc1 $KEY_PUB_1 $KEY_PUB_1
cleos create account eosio acc2 $KEY_PUB_1 $KEY_PUB_1
cleos create account eosio acc3 $KEY_PUB_1 $KEY_PUB_1
cleos create account eosio acc4 $KEY_PUB_1 $KEY_PUB_1
cleos create account eosio acc5 $KEY_PUB_1 $KEY_PUB_1


cleos create account eosio accballot $KEY_PUB_2 $KEY_PUB_2

cleos set contract accballot ../ballot -p accballot


echo ""
echo ""
echo "********run test case **********"
echo ""



echoCmd "cleos push action accballot addposposal '["baidu"]' --permission initb@active"

cleos push action accballot addposposal '["baidu"]' -p accballot
cleos push action accballot addposposal '["alibaba"]' -p accballot
cleos push action accballot addposposal '["163"]' -p accballot
cleos push action accballot addposposal '["360"]' -p accballot
cleos push action accballot addposposal '["qq"]' -p accballot
cleos push action accballot addposposal '["yy"]' -p accballot


echoCmd "cleos get table ballot initb games"

