#!/bin/bash
echoCmd() {
	echo -e "\033[31;46m"$1"\033[0m"
}
WORK_DIR="$( dirname "$0"  )"
cd $WORK_DIR
WORK_DIR=`pwd`
OS=`uname`

#cleos create key

#cleos wallet create -n vot
#Private key: 5K2mzpWm7N6RRYEndfV1LgMKXo51oNHT8GfWHWYCVAxT3tVjthg
#Public key: EOS7Atb9bLnsUXdHmC9HVS8NaF6i1wwY13grCBnX3pmxz4rMNjziM

#Private key: 5KQnniY4P6T3PuYAGcvrBR3BBPgd1vNRATMuNPxvgVKSQMcpMZw
#Public key: EOS7tcXZthMFBJ51PjFt2ag7fU65buvCiNQWSACxpoft5cFQc6DeK

KEY_PRIVATE_1= 5K2mzpWm7N6RRYEndfV1LgMKXo51oNHT8GfWHWYCVAxT3tVjthg
KEY_PUB_1= EOS7Atb9bLnsUXdHmC9HVS8NaF6i1wwY13grCBnX3pmxz4rMNjziM

KEY_PRIVATE_2= 5KQnniY4P6T3PuYAGcvrBR3BBPgd1vNRATMuNPxvgVKSQMcpMZw
KEY_PUB_2= EOS7tcXZthMFBJ51PjFt2ag7fU65buvCiNQWSACxpoft5cFQc6DeK




#PW5JfnU5vDtADBV8Ac4zDQCdL5n9HxngTKzMPCP4hXyXNNS3iUoz2
#build code
cd $WORK_DIR/ballot
#eosiocpp -o ballot.wast ballot.cpp
#eosiocpp -g ballot.abi ballot.cpp
cd -
#
#
#if [ ! -f $WORK_DIR"/../passwd.txt" ];then
#    ../setup.sh
#fi
cat $WORK_DIR/../passwd.txt | cleos wallet unlock -n vot
cleos wallet unlock -n vot --password PW5JfnU5vDtADBV8Ac4zDQCdL5n9HxngTKzMPCP4hXyXNNS3iUoz2
cleos wallet import -n vot $KEY_PRIVATE_1
cleos wallet import -n vot $KEY_PRIVATE_2

cleos wallet import -n vot 5KQwrPbwdL6PhXujxW37FSSQZ1JiwsST4cqQzDeyXtP79zkvFD3
cleos wallet import  5K2mzpWm7N6RRYEndfV1LgMKXo51oNHT8GfWHWYCVAxT3tVjthg
cleos wallet import  5KQnniY4P6T3PuYAGcvrBR3BBPgd1vNRATMuNPxvgVKSQMcpMZw

##kill old nodeos
#if [ $OS"x" == "Darwinx" ];then
#    ps a > ./tmp.txt
#    grep "nodeos" ./tmp.txt|awk '{print $1}'|xargs kill -9
#    rm ./tmp.txt
#else
#    ps auxf|grep "nodeos -e"|awk '{print $2}'|xargs kill -9
#fi
#launch nodeos --resync  –replay-blockchain --hard-replay-blockchain
#echo "launch nodeos ......"
#nohup nodeos -e -p eosio --contracts-console --plugin eosio::chain_api_plugin --plugin #eosio::history_api_plugin --plugin eosio::http_plugin   --data-dir ./.tmpdata/eosio 2>&1 #1>nodeos.log &
#sleep 2


cleos create account eosio acc1 $KEY_PUB_1 $KEY_PUB_1
sleep 2
cleos create account eosio acc2 $KEY_PUB_1 $KEY_PUB_1
sleep 2
cleos create account eosio acc3 $KEY_PUB_1 $KEY_PUB_1
sleep 2
cleos create account eosio acc4 $KEY_PUB_1 $KEY_PUB_1
sleep 2
cleos create account eosio acc5 $KEY_PUB_1 $KEY_PUB_1
sleep 2

cleos create account eosio acc11 EOS7Atb9bLnsUXdHmC9HVS8NaF6i1wwY13grCBnX3pmxz4rMNjziM EOS7Atb9bLnsUXdHmC9HVS8NaF6i1wwY13grCBnX3pmxz4rMNjziM
cleos create account eosio acc21 EOS7Atb9bLnsUXdHmC9HVS8NaF6i1wwY13grCBnX3pmxz4rMNjziM EOS7Atb9bLnsUXdHmC9HVS8NaF6i1wwY13grCBnX3pmxz4rMNjziM
cleos create account eosio acc31 EOS7Atb9bLnsUXdHmC9HVS8NaF6i1wwY13grCBnX3pmxz4rMNjziM EOS7Atb9bLnsUXdHmC9HVS8NaF6i1wwY13grCBnX3pmxz4rMNjziM
cleos create account eosio acc41 EOS7Atb9bLnsUXdHmC9HVS8NaF6i1wwY13grCBnX3pmxz4rMNjziM EOS7Atb9bLnsUXdHmC9HVS8NaF6i1wwY13grCBnX3pmxz4rMNjziM
cleos create account eosio acc11 EOS7Atb9bLnsUXdHmC9HVS8NaF6i1wwY13grCBnX3pmxz4rMNjziM EOS7Atb9bLnsUXdHmC9HVS8NaF5i1wwY13grCBnX3pmxz4rMNjziM

 cleos get accounts EOS7Atb9bLnsUXdHmC9HVS8NaF6i1wwY13grCBnX3pmxz4rMNjziM

cleos create account eosio accballot $KEY_PUB_2 $KEY_PUB_2

cleos create account eosio accballot1 EOS7tcXZthMFBJ51PjFt2ag7fU65buvCiNQWSACxpoft5cFQc6DeK EOS7tcXZthMFBJ51PjFt2ag7fU65buvCiNQWSACxpoft5cFQc6DeK

cleos set account permission accballot1 active '{"threshold": 1,"keys": [{"key": "EOS7tcXZthMFBJ51PjFt2ag7fU65buvCiNQWSACxpoft5cFQc6DeK","weight": 1}],"accounts": [{"permission":{"actor":"accballot1","permission":"eosio.code"},"weight":1}]}' owner -p accballot1


cleos set contract accballot1 ../ballot -p accballot1


echo ""
echo ""
echo "********run test case **********"
echo ""



echoCmd "增加投票选项 cleos push action accballot addposposal '["baidu"]' --permission initb@active"

cleos push action accballot1 addposposal '["baidu"]' -p accballot1
cleos push action accballot1 addposposal '["alibaba"]' -p accballot1
cleos push action accballot1 addposposal '["163"]' -p accballot1
cleos push action accballot1 addposposal '["360"]' -p accballot1
cleos push action accballot1 addposposal '["qq"]' -p accballot1
cleos push action accballot1 addposposal '["yy"]' -p accballot1


echoCmd "添加投票人"
 cleos push action accballot1 addvoter '["acc1",1]' -p accballot1
cleos push action accballot1 addvoter '["acc21",1]' -p accballot1
cleos push action accballot1 addvoter '["acc31",1]' -p accballot1
cleos push action accballot1 addvoter '["acc41",1]' -p accballot1
 cleos push action accballot1 addvoter '["acc51",1]' -p accballot1
cleos push action accballot1 addvoter '["acc11",1]' -p accballot1

echoCmd "开始投票"

cleos push action accballot1 allproposal '["acc1"]'  -p acc1
cleos push action accballot1 vote '["acc1","qq"]' -p acc1
cleos push action accballot1 vote '["acc2","qq"]' -p acc2
cleos push action accballot1 vote '["acc3","163"]' -p acc3
cleos push action accballot1 vote '["acc4","qq"]' -p acc4
cleos push action accballot1 delegate '["acc5","acc3"]' -p acc5

cleos push action accballot1 vote '["acc11","qq"]' -p acc11

cleos push action accballot1 vote '["acc1","qq"]' -p acc1
cleos push action accballot1 vote '["acc21","qq"]' -p acc21
cleos push action accballot1 vote '["acc31","163"]' -p acc31
cleos push action accballot1 vote '["acc41","qq"]' -p acc41


echoCmd "投票结果"

cleos push action accballot1 winproposal '[acc1]' -p acc1



