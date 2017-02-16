<?php
include "php/banco_conexao.php";
$nome = $_POST['nome'];

$resultado = mysqli_query($conexao, "DELETE FROM usuarios WHERE nome="."'$nome'") or die("Não foi possível executar a SQL:".mysqli_error($conexao));

if($resultado == TRUE){
    echo "<br/>Usuário removido com sucesso!";
    echo "<br/><a href='index.html'>Voltar</a>";
}else{
    echo "<br/>Erro na remoção!";
    echo "<br/><a href='index.html'>Voltar</a";
}
mysqli_close($conexao);

?>