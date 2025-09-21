programa
{
	inclua biblioteca Matematica

	funcao inicio()
	{
		// Declaração de Vetores com tamanho literal
		cadeia nomes[3]
		real precos_anteriores[3], precos_atuais[3], variacoes[3]
		cadeia situacoes[3]

		// --- FASE 1: ENTRADA DE DADOS ---
		para (inteiro i = 0; i < 3; i++)
		{
			escreva("-----------------------------------------\n")
			escreva("Digite os dados do ", i + 1, "º produto:\n")
			escreva("Nome do produto: ")
			leia(nomes[i])
			escreva("Preço no mês anterior (R$): ")
			leia(precos_anteriores[i])
			escreva("Preço no mês atual (R$): ")
			leia(precos_atuais[i])
		}
		limpa()

		// --- FASE 2: PROCESSAMENTO DOS DADOS ---
		para (inteiro i = 0; i < 3; i++)
		{
			se (precos_anteriores[i] == 0.0) {
				variacoes[i] = 0.0
			} senao {
				variacoes[i] = ((precos_atuais[i] - precos_anteriores[i]) / precos_anteriores[i]) * 100.0
			}

			se (variacoes[i] > 0.0) {
				situacoes[i] = "AUMENTO"
			} senao se (variacoes[i] < 0.0) {
				situacoes[i] = "QUEDA"
			} senao {
				situacoes[i] = "ESTÁVEL"
			}
		}

		// --- FASE 3: SAÍDA DO RELATÓRIO FINAL ---
		escreva("\n======= Relatório Final da Cesta Básica =======\n\n")

		para (inteiro i = 0; i < 3; i++)
		{
			escreva("Produto: ", nomes[i], "\n")
			escreva("Preço Anterior: R$ ", precos_anteriores[i], "\n")
			escreva("Preço Atual: R$ ", precos_atuais[i], "\n")
			escreva("Variação Percentual: ", Matematica.arredondar(variacoes[i], 2), "%\n")
			escreva("Situação: ", situacoes[i], "\n")
			
			se (variacoes[i] > 10.0) {
				escreva("ATENÇÃO: Aumento abusivo identificado!\n")
			}
			escreva("-----------------------------------------\n")
		}
	}
}