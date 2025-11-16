#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <string>
#include <vector>

using namespace ftxui;

int main() {
    // Estado da aplicação
    std::string nome;
    int idade = 25;
    int progresso = 50;
    int opcao_selecionada = 0;
    
    std::vector<std::string> opcoes = {
        "🚀 Opção 1: Começar",
        "⚙️  Opção 2: Configurar",
        "📊 Opção 3: Ver Estatísticas",
        "❌ Opção 4: Sair"
    };
    
    bool checkbox1 = false;
    bool checkbox2 = true;
    
    // Componentes interativos
    auto input_nome = Input(&nome, "Digite seu nome...");
    auto slider_idade = Slider("Idade: ", &idade, 0, 100, 1);
    auto slider_progresso = Slider("Progresso: ", &progresso, 0, 100, 5);
    
    auto radiobox = Radiobox(&opcoes, &opcao_selecionada);
    
    auto check1 = Checkbox("Habilitar notificações", &checkbox1);
    auto check2 = Checkbox("Modo escuro", &checkbox2);
    
    auto botao_confirmar = Button("✓ Confirmar", [&] {
        // Ação do botão
    });
    
    auto botao_cancelar = Button("✗ Cancelar", [&] {
        // Ação do botão
    });
    
    // Layout principal
    auto component = Container::Vertical({
        input_nome,
        slider_idade,
        slider_progresso,
        Renderer([] { return separator(); }),
        radiobox,
        Renderer([] { return separator(); }),
        check1,
        check2,
        Renderer([] { return separator(); }),
        Container::Horizontal({
            botao_confirmar,
            botao_cancelar,
        }),
    });
    
    // Adiciona decoração visual
    auto renderer = Renderer(component, [&] {
        return vbox({
            // Cabeçalho
            text("╔════════════════════════════════════╗") | color(Color::Cyan) | bold,
            text("║   🎨 FTXUI Demo Application 🎨   ║") | color(Color::Cyan) | bold,
            text("╚════════════════════════════════════╝") | color(Color::Cyan) | bold,
            separator(),
            
            // Seção de informações
            hbox({
                text("Nome: ") | bold,
                text(nome.empty() ? "(vazio)" : nome) | color(Color::Yellow),
            }),
            hbox({
                text("Idade: ") | bold,
                text(std::to_string(idade) + " anos") | color(Color::Green),
            }),
            
            // Barra de progresso visual
            hbox({
                text("Progresso: ") | bold,
                gauge(progresso / 100.0) | color(Color::Blue) | flex,
                text(" " + std::to_string(progresso) + "%"),
            }),
            
            separator(),
            
            // Entrada de texto
            hbox({
                text("📝 ") | bold,
                input_nome->Render(),
            }) | border,
            
            separator(),
            
            // Sliders
            vbox({
                text("🎚️  Controles:") | bold | color(Color::Magenta),
                slider_idade->Render(),
                slider_progresso->Render(),
            }) | border,
            
            separator(),
            
            // Menu de opções
            vbox({
                text("📋 Menu:") | bold | color(Color::Blue),
                radiobox->Render(),
            }) | border,
            
            separator(),
            
            // Checkboxes
            vbox({
                text("⚙️  Configurações:") | bold | color(Color::Green),
                check1->Render(),
                check2->Render(),
            }) | border,
            
            separator(),
            
            // Botões
            hbox({
                botao_confirmar->Render() | color(Color::GreenLight),
                text("  "),
                botao_cancelar->Render() | color(Color::RedLight),
            }) | center,
            
            separator(),
            
            // Rodapé
            text("💡 Use TAB para navegar | ESC ou Ctrl+C para sair") 
                | dim | center,
            
        }) | border | center;
    });
    
    // Inicia a tela interativa
    auto screen = ScreenInteractive::Fullscreen();
    screen.Loop(renderer);
    
    return 0;
}

