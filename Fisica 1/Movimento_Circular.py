from vpython import *
import numpy as np

# Configuração da cena
scene = canvas(title="Simulação de Movimento Circular", 
               width=1400, height=900, 
               background=color.white, 
               center=vector(0,0,0))

# Texto explicativo
instructions = label(pos=vector(0,-12,0), 
                    text="""SIMULAÇÃO DE MOVIMENTO CIRCULAR
Objeto azul: partícula | Vetor verde: velocidade | Vetor vermelho: força centrípeta | Vetor laranja: aceleração tangencial""",
                    color=color.black, height=16, box=False)

# Parâmetros iniciais
raio = 5
massa = 1
velocidade_inicial = 2
aceleracao_tangencial = 0
forca_centripeta = massa * velocidade_inicial**2 / raio
gravidade = 9.8

# Variáveis de estado
velocidade_atual = velocidade_inicial
tempo = 0
angulo = 0

# Controles interativos
def set_raio(r):
    global raio, forca_centripeta
    raio = r.value
    forca_centripeta = massa * velocidade_atual**2 / raio
    trajetoria.radius = raio

def set_massa(m):
    global massa, forca_centripeta
    massa = m.value
    forca_centripeta = massa * velocidade_atual**2 / raio

def set_velocidade_inicial(v):
    global velocidade_inicial, velocidade_atual, forca_centripeta
    velocidade_inicial = v.value
    velocidade_atual = velocidade_inicial
    forca_centripeta = massa * velocidade_atual**2 / raio

def set_aceleracao(a):
    global aceleracao_tangencial
    aceleracao_tangencial = a.value

# Sliders
scene.append_to_caption("\n\nControles:\n")

scene.append_to_caption("\nRaio da trajetória: ")
slider_raio = slider(pos=scene.title_anchor, min=1, max=10, value=raio, length=300, bind=set_raio)
scene.append_to_caption(f" {raio} m")

scene.append_to_caption("\n\nMassa do objeto: ")
slider_massa = slider(pos=scene.title_anchor, min=0.1, max=5, value=massa, length=300, bind=set_massa)
scene.append_to_caption(f" {massa} kg")

scene.append_to_caption("\n\nVelocidade inicial: ")
slider_velocidade = slider(pos=scene.title_anchor, min=0.5, max=5, value=velocidade_inicial, length=300, bind=set_velocidade_inicial)
scene.append_to_caption(f" {velocidade_inicial} m/s")

scene.append_to_caption("\n\nAceleração tangencial: ")
slider_aceleracao = slider(pos=scene.title_anchor, min=-1, max=1, step=0.1, value=aceleracao_tangencial, length=300, bind=set_aceleracao,wtitle="teste targa")
scene.append_to_caption(f" {aceleracao_tangencial} m/s²")

# Botão reset
def reset_simulacao(b):
    global velocidade_atual, tempo, angulo
    velocidade_atual = velocidade_inicial
    tempo = 0
    angulo = 0
    objeto.pos = vector(raio, 0, 0)

scene.append_to_caption("\n\n")
button(pos=scene.title_anchor, text="Resetar Simulação", bind=reset_simulacao)

# Objetos 3D
centro = sphere(pos=vector(0,0,0), radius=0.2, color=color.red)
objeto = sphere(pos=vector(raio,0,0), radius=0.5, color=color.blue)
trajetoria = ring(pos=vector(0,0,0), axis=vector(0,0,1), radius=raio, thickness=0.05, color=color.gray(0.8))

# Vetores
vetor_velocidade = arrow(pos=objeto.pos, axis=vector(0,velocidade_inicial,0), color=color.green, shaftwidth=0.2)
vetor_forca = arrow(pos=objeto.pos, axis=vector(-raio,0,0), color=color.red, shaftwidth=0.2)
vetor_aceleracao_tang = arrow(pos=objeto.pos, axis=vector(0,0,0), color=color.orange, shaftwidth=0.15)

# Gráficos temporais (lado esquerdo)
graph_velocidade = graph(title="Velocidade e Aceleração vs Tempo", xtitle="Tempo (s)", ytitle="Magnitude", 
                        width=450, height=300, background=color.white)
vel_curve = gcurve(graph=graph_velocidade, color=color.blue, label="Velocidade (m/s)")
acel_curve = gcurve(graph=graph_velocidade, color=color.orange, label="Aceleração (m/s²)")

graph_forcas_tempo = graph(title="Forças vs Tempo", xtitle="Tempo (s)", ytitle="Força (N)", 
                         width=450, height=300, background=color.white)
fc_curve = gcurve(graph=graph_forcas_tempo, color=color.red, label="Força centrípeta")
ft_curve = gcurve(graph=graph_forcas_tempo, color=color.purple, label="Força tangencial")

# Gráficos de relações físicas (lado direito)
graph_fc_vs_v = graph(title="Força Centrípeta vs Velocidade (Fₐ vs v)", xtitle="Velocidade (m/s)", ytitle="Força Centrípeta (N)", 
                     width=450, height=300, background=color.white, xmin=0, xmax=5, ymin=0, ymax=50)
fc_vs_v_curve = gcurve(graph=graph_fc_vs_v, color=color.red)

graph_fc_vs_r = graph(title="Força Centrípeta vs Raio (Fₐ vs R)", xtitle="Raio (m)", ytitle="Força Centrípeta (N)", 
                     width=450, height=300, background=color.white, xmin=1, xmax=10, ymin=0, ymax=25)
fc_vs_r_curve = gcurve(graph=graph_fc_vs_r, color=color.blue)

graph_fc_vs_m = graph(title="Força Centrípeta vs Massa (Fₐ vs m)", xtitle="Massa (kg)", ytitle="Força Centrípeta (N)", 
                     width=450, height=300, background=color.white, xmin=0, xmax=5, ymin=0, ymax=25)
fc_vs_m_curve = gcurve(graph=graph_fc_vs_m, color=color.green)

graph_v_vs_r = graph(title="Velocidade vs Raio para Fₐ constante (v vs R)", xtitle="Raio (m)", ytitle="Velocidade (m/s)", 
                    width=450, height=300, background=color.white, xmin=1, xmax=10, ymin=0, ymax=5)
v_vs_r_curve = gcurve(graph=graph_v_vs_r, color=color.purple)

# Função para atualizar gráficos de relações
def atualizar_graficos_relacoes():
    # Limpa gráficos
    fc_vs_v_curve.delete()
    fc_vs_r_curve.delete()
    fc_vs_m_curve.delete()
    v_vs_r_curve.delete()
    
    # Força vs Velocidade (raio e massa fixos)
    for v in np.linspace(0.1, 5, 50):
        F = massa * v**2 / raio
        fc_vs_v_curve.plot(v, F)
    
    # Força vs Raio (velocidade e massa fixas)
    for r in np.linspace(1, 10, 50):
        F = massa * velocidade_atual**2 / r
        fc_vs_r_curve.plot(r, F)
    
    # Força vs Massa (velocidade e raio fixos)
    for m in np.linspace(0.1, 5, 50):
        F = m * velocidade_atual**2 / raio
        fc_vs_m_curve.plot(m, F)
    
    # Velocidade vs Raio para força constante (F = 5N)
    F_constante = 5
    for r in np.linspace(1, 10, 50):
        v = np.sqrt(F_constante * r / massa)
        v_vs_r_curve.plot(r, v)

# Animação
dt = 0.01
atualizar_graficos_relacoes()

while True:
    rate(100)
    
    # Atualiza velocidade
    velocidade_atual += aceleracao_tangencial * dt
    if velocidade_atual < 0:
        velocidade_atual = 0
    
    # Atualiza ângulo e posição
    angulo += (velocidade_atual / raio) * dt
    x = raio * np.cos(angulo)
    y = raio * np.sin(angulo)
    objeto.pos = vector(x, y, 0)
    
    # Atualiza vetores
    vetor_velocidade.pos = objeto.pos
    vetor_velocidade.axis = vector(-velocidade_atual*np.sin(angulo), velocidade_atual*np.cos(angulo), 0)
    
    forca_centripeta = massa * velocidade_atual**2 / raio
    vetor_forca.pos = objeto.pos
    vetor_forca.axis = vector(-x, -y, 0).norm() * forca_centripeta * 0.3
    
    vetor_aceleracao_tang.pos = objeto.pos
    if velocidade_atual > 0:
        vetor_aceleracao_tang.axis = vector(-np.sin(angulo), np.cos(angulo), 0).norm() * aceleracao_tangencial * 0.5
    else:
        vetor_aceleracao_tang.axis = vector(0,0,0)
    
    forca_tangencial = massa * aceleracao_tangencial
    
    # Atualiza gráficos temporais
    vel_curve.plot(tempo, velocidade_atual)
    acel_curve.plot(tempo, aceleracao_tangencial)
    fc_curve.plot(tempo, forca_centripeta)
    ft_curve.plot(tempo, forca_tangencial)
    
    # Atualiza gráficos de relações periodicamente
    if tempo % 1 < dt:  # Atualiza a cada ~1 segundo
        atualizar_graficos_relacoes()
    
    # Atualiza valores nos sliders
    slider_raio.caption = f"Raio: {raio} m"
    slider_massa.caption = f"Massa: {massa} kg"
    slider_velocidade.caption = f"Velocidade inicial: {velocidade_inicial} m/s"
    slider_aceleracao.caption = f"Aceleração tangencial: {aceleracao_tangencial} m/s²"
    
    # Informações
    scene.caption = f"""
    Parâmetros atuais:
    Massa: {massa} kg | Raio: {raio} m 
    Velocidade atual: {velocidade_atual:.2f} m/s | Aceleração: {aceleracao_tangencial:.2f} m/s²
    Força centrípeta: {forca_centripeta:.2f} N | Força tangencial: {forca_tangencial:.2f} N
    Período instantâneo: {2*np.pi*raio/velocidade_atual:.2f} s (quando v>0)
    """
    
    tempo += dt
