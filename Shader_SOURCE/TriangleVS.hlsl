
struct VSIn
{
	float3 Pos : POSITION;
    float4 Color : COLOR;
};

struct VSOut
{
    float4 Pos : SV_Position;
    float4 Color : COLOR;
};

cbuffer Transform : register(b0)
{
    float4 Pos;
}

cbuffer Color : register(b1)
{
    float4 Color;
}

cbuffer Scale : register(b2)
{
    float4 Scale;
}

VSOut main(VSIn In)
{
    VSOut Out = (VSOut) 0.0f;
    
    Out.Pos = float4(In.Pos, 1.0f);
    
    Out.Pos.x *= Scale.x;
    Out.Pos.y *= Scale.x;
    
    Out.Pos.x += Pos.x;
    Out.Pos.y += Pos.y;
    
    
    Out.Color = In.Color;
    Out.Color = Color;
    
    
    
    return Out;
};






