#include<stdio.h>
#include<opus/opus.h>
int main(int argc, char* argv[])
{
    FILE* fp =fopen("record.wav", "r");
    char buffer[4800];
    OpusEncoder * enc;
    OpusDecoder * dec;
    int error;
    enc = opus_encoder_create(48000, 2, OPUS_APPLICATION_VOIP, &error);
    dec = opus_decoder_create(48000, 2, &error);
    unsigned char data[4000];
    FILE* fp_out = fopen("record.opus", "w");
    FILE* fp_wav = fopen("decode.wav", "w");
    while(fread(buffer, 1, 480, fp))
    {
        int len = opus_encode(enc, (opus_int16*)buffer, 120, data, 4000);
        if(len > 0)
        {
            fwrite(data, 1, len, fp_out);
            len = opus_decode(dec, data, len, (opus_int16*)buffer, 4800, 0);
            if(len)
            {
                fwrite(buffer, 4, len, fp_wav);
            }
        }
        else
        {
            printf("%s\n", opus_strerror(len));
            goto exit;
        }
    }
exit:
    fclose(fp);
    fclose(fp_wav);
    fclose(fp_out);
    return 0;
}
