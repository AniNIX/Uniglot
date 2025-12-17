#!/bin/bash

function GenerateTLSAHash {
    ### Generate DANE TLSA
    # param 1: Certfile
    openssl x509 -in "$1" -noout -pubkey | openssl pkey -pubin -outform DER | openssl dgst -sha256 -binary | hexdump -ve '/1 "%02x"'
}
function GenerateTLSA-311 {
    ### Generate DANE TLSA
    # param 1: identity
    printf "3 1 1 $(GenerateTLSAHash /etc/letsencrypt/live/"$1"/cert.pem)\n"
}

function GenerateTLSA-211 {
    ### Generate DANE TLSA
    # param 1: identity
    printf "2 1 1 $(GenerateTLSAHash /etc/letsencrypt/live/"$1"/chain.pem)\n"
}

function GenerateTLSA {
    ### Generate DANE TLSA
    # param 1: identity
    GenerateTLSA-311 "$1"
    GenerateTLSA-211 "$1"
}

function GenerateCAA {
    ### Generate CAA
    # Pending an attribute on the chain to derive this from.
    echo '128 issue "letsencrypt.org"'
}

function GenerateSSHFP {
    ### Generate the SSHFP
    ssh-keyscan -D localhost | grep -E '1 2|4 2' | sed 's/localhost IN SSHFP //'
}
